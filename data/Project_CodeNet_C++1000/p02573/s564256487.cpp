#include<bits/stdc++.h>
using namespace std;

const int max_n=2e5+10;
int p[max_n];
int cnt[max_n];
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {p[i] = i,cnt[i]=1;}
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        int pa=find(a),pb=find(b);
        if (pa!=pb) {
           p[pa]=pb;
           cnt[pb]+=cnt[pa];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
            res = max(res, cnt[i]);
    }
    cout << res<< endl;
    return 0;
}