#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)
#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define CHMAX(a,b) a = max(a,b)
#define CHMIN(a,b) a = min(a,b)
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define e1 first
#define e2 second
#define newline putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const int INF = 1e7;
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;
const VI dx = {1, 0, -1, 0};
const VI dy = {0, 1, 0, -1};


int main()
{
    int x, y, a, b, c;
    cin>>x>>y>>a>>b>>c;
    VLL p(a), q(b), r(c);
    REP(i,a) cin>>p[i];
    REP(i,b) cin>>q[i];
    REP(i,c) cin>>r[i];
    SORT(p); SORT(q); SORT(r);
    VLL candidate;
    FOR(i,a-x,a) candidate.push_back(p[i]);
    FOR(i,b-y,b) candidate.push_back(q[i]);
    SORT(candidate);
    int idx = c - 1;
    ll ans = 0ll;
    REP(i,x+y) {
        if (idx >= 0 && candidate[i] < r[idx]) {
            ans += r[idx];
            idx--;
        } else {
            ans += candidate[i];
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;

    return 0;
}
