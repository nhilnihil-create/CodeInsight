#include <cstdio>
#include <queue>
using namespace std;


#define INF 1 << 30
#define min(a,b) ((a) > (b) ? (b) : (a))
typedef struct P {
	int x, y;
	P(){}
	P(int i, int j) {
		x = i;
		y = j;
	}
	P operator+(const P r) {
		return{ x + r.x,y + r.y };
	}
	bool operator==(const P r) {
		return x == r.x && y == r.y;
	}
}P;

int H, W, N;
char map[1001][1001];
bool dp[1001][1001];
P mv[4] = { {-1,0},{0,-1},{0,1},{1,0} };
P fac[10];
queue<P> q;

void ini() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			dp[i][j] = false;
		}
	}
}

inline bool ok(P p) {
	return p.x >= 0 && p.x < H && p.y >= 0 && p.y < W && !dp[p.x][p.y] && map[p.x][p.y] != 'X';
}

int road(P s, P e) {
	ini();
	q = queue<P>();
	q.push(s);
	int l = 0;
	while (true) {
		l++;
		int ql = q.size();
		if (ql == 0) break;
		for (int i = 0; i < ql; i++) {
			P f = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				P p = f + mv[j];
				if (ok(p)) {
					if (p == e) {
						return l;
					}
					q.push(p);
					dp[p.x][p.y] = true;
				}
			}
		}
	}
	return -1;
}

int main(){
	scanf("%d%d%d", &H, &W, &N);
	for (int i = 0; i < H; i++) {
		scanf("%s", map[i], 1001);
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 'S') {
				fac[0] = P(i, j);
			}
			else if (map[i][j] > '0' && map[i][j] <= '9') {
				fac[(unsigned)(map[i][j] - '0')] = P(i, j);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += road(fac[i], fac[i + 1]);
	}
	printf("%d\n", ans);

	return 0;
}