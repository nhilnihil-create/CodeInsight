#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

const int INF = 0x3f3f3f3f;

void run_case() {
    int n, m;
    cin >> n >> m;
    vector<int> cost(m), mask(m);
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cost[i] = a;
        while(b--) {
            int c; cin >> c;
            c--;
            mask[i] |= (1 << c);
        }
    }
    vector<int> d(1<<n, INF), e(1<<n);
    d[0] = 0;
    for(int i = 0; i < m; ++i) {
        copy(d.begin(), d.end(), e.begin());
        for(int k = 0; k < (1<<n); ++k) {
            int newk = k | mask[i];
            e[newk] = min(e[newk], d[k] + cost[i]);
        }
        swap(d, e);
    }
    cout << (d[(1<<n)-1] == INF? -1: d[(1<<n)-1]);
}


int main() {
    //freopen("input", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}