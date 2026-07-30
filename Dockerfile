FROM node:22-alpine AS build
WORKDIR /app
COPY backend/package*.json ./
RUN npm config set legacy-peer-deps true && npm ci
COPY backend/ .

FROM node:22-alpine AS production
WORKDIR /app
RUN apk add --no-cache tini g++ gcc musl-dev make cppcheck
COPY --from=build /app/package*.json ./
RUN npm config set legacy-peer-deps true && npm ci --omit=dev
COPY --from=build /app/ .
USER node
EXPOSE 5000
ENV PORT=5000
HEALTHCHECK --interval=30s --timeout=5s --start-period=15s --retries=3 \
  CMD wget --no-verbose --tries=1 --spider http://localhost:5000/api/health || exit 1
ENTRYPOINT ["/sbin/tini", "--"]
CMD ["node", "server.js"]
