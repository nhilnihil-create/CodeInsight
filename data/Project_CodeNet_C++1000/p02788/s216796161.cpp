#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


void run_case() {
    int n, d, a;
    cin >> n >> d >> a;
    vector<pii> m(n);
    for(auto &x: m) cin >> x.first >> x.second;
    sort(m.begin(), m.end());
    vector<LL> c(n+1);
    LL ans = 0;
    for(int i = 0, j = 0; i < n; ++i) {
        while(j < n && m[j].first <= m[i].first + 2*d) j++;
        LL need = max((m[i].second - c[i]*a+a-1) / a, 0LL);
        c[i] += need;
        c[j] -= need;
        c[i+1] += c[i];
        ans += need;
    }
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}
