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

int s(ll n, ll k)
{
    if (n % k == 1) {
        return 1;
    } else if (n % k == 0) {
        return s(n / k, k);
    } else {
        return 0;
    }
}

int main()
{
    ll n, ans = 0;
    cin>>n;

    set<ll> div;
    ll m;
    m = n;
    for (ll i = 1; i * i <= m; i++) {
        if (m % i != 0)
            continue;

        div.insert(i);
        div.insert(m/i);
    }
    m = n - 1;
    for (ll i = 1; i * i <= m; i++) {
        if (m % i != 0)
            continue;

        div.insert(i);
        div.insert(m/i);
    }
    div.erase(1);

    REPITR(itr, div) {
        ans += s(n, *itr);
        //cout<<*itr<<" "<<s(n, *itr)<<endl;
    }
    cout<<ans<<endl;

    return 0;
}
