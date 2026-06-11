#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 2019;
const ll inf = 1e15;

ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}

int main(){FIN

    map<ll,ll> r;
    string s;cin>>s;

    r[0]++;
    ll n = s.size();
    ll now=0;
    REP(i,n){
        now += (s[n-1-i]-'0') * power(10, i);
        now %= 2019;
        r[now]++;
    }
    ll ans=0;
    for(auto p:r){
        ans += p.second * (p.second-1) /2;
    }
    cout<<ans<<endl;
    return 0;
}