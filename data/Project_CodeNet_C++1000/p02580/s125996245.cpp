#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

const int CN = 3e5 + 5;

int read(){
    int s = 0,ne = 1; char c = getchar();
    while(c < '0' || c > '9') ne = c == '-' ? -1 : 1, c = getchar();
    while(c >= '0' && c <= '9') s = (s << 1) + (s << 3) + c - '0', c = getchar();
    return s * ne;
}

int H, W, M; vector<int> line[CN];
class SGT {
  public: int d[CN << 2];
    #define lc k << 1
    #define rc k << 1 | 1
    void md(int l, int r, int k, int p, int x){
        if(l == r) return (void)(d[k] += x);
        int m = (l + r) >> 1; if(p <= m) md(l, m, lc, p, x); else md(m + 1, r, rc, p, x);
        d[k] = max(d[lc], d[rc]);
    }
    int qu() {return d[1];}
} D;

int main()
{
    // freopen("_in.in", "r", stdin);

    H = read(), W = read(), M = read();
    for(int i = 1; i <= M; i++){
        int h = read(), w = read(); line[h].push_back(w), D.md(1, W, 1, w, 1);
    }

    int ans = 0;
    for(int i = 1; i <= H; i++){
        int sz = line[i].size();
        for(int j = 0; j < sz; j++) D.md(1, W, 1, line[i][j], -1);
        ans = max(ans, sz + D.qu());
        for(int j = 0; j < sz; j++) D.md(1, W, 1, line[i][j], 1);
    }

    printf("%d", ans);
}