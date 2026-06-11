#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    constexpr int INF = 1 << 30;
    int N; cin >> N;
    vector<pii> m(2,{-INF,INF});
    REP(i,N) {
        int x, y;
        cin >> x >> y;
        m[0].first = max(m[0].first,x+y);
        m[0].second = min(m[0].second,x+y);
        m[1].first = max(m[1].first,x-y);
        m[1].second = min(m[1].second,x-y);
    }
    OUT(max(abs(m[0].first-m[0].second),abs(m[1].first - m[1].second)))

    return 0;
}