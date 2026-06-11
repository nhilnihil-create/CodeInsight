#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int CN = 2e5 + 5;

int read(){
    int s = 0,ne = 1; char c = getchar();
    while(c < '0' || c > '9') ne = c == '-' ? -1 : 1, c = getchar();
    while(c >= '0' && c <= '9') s = (s << 1) + (s << 3) + c - '0', c = getchar();
    return s * ne;
}

int n, m, sz[CN];

class DSU {
  public: int fa[CN]; DSU() {for(int i = 0; i <= 200000; i++) fa[i] = i;}
    int fd(int x) {return fa[x] ^ x ? fa[x] = fd(fa[x]) : x;}
} D;

int main()
{
    // freopen("_in.in", "r", stdin);
    n = read(), m = read();
    for(int i = 1; i <= n; i++) sz[i] = 1;
    while(m--){
        int u = read(), v = read();
        u = D.fd(u), v = D.fd(v);
        if(u ^ v){
            sz[u] += sz[v], sz[v] = 0;
            D.fa[v] = u;
        }
    }
    int mx = 0; for(int i = 1; i <= n; i++) mx = max(mx, sz[i]);
    printf("%d", mx);
}