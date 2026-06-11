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
    int n;
    ll ans;
    string s;
    cin>>n>>s;

    VI r, g, b;
    REP(i,n) {
        if (s[i] == 'R') r.push_back(i);
        else if (s[i] == 'G') g.push_back(i);
        else if (s[i] == 'B') b.push_back(i);
    }

    ans = r.size() * g.size() * b.size();

    REP(i,n-2) {
        FOR(j,1,n) {
            if (i + j * 2 >= n) break;

            if (s[i] != s[i+j] && s[i] != s[i+j*2] && s[i+j] != s[i+j*2])
                ans--;
        }
    }

    cout<<ans<<endl;

    return 0;
}
