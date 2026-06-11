#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
const ll INF = 1e18;
using namespace std;
// using namespace atcoder;


void Main()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    map<ll, ll> cnt;
    ll res = 0;
    rep(i, n) {
        ll ref = 1+i - A[i];
        ll c = cnt.count(ref) ? cnt[ref] : 0;
        res += c;

        ll v = 1+i + A[i];
        cnt[v]++;
    }
    put(res);
}
signed main(){ Main();return 0;}