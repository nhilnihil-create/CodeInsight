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

    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];
    
    sort(all(A));
    sort(all(B));

    if (n % 2 == 0) {
        ll mA = A[n/2-1] + A[n/2];
        ll mB = B[n/2-1] + B[n/2];
        ll res = mB - mA + 1;
        put(res);
    }
    else {
        ll mA = A[n/2];
        ll mB = B[n/2];
        ll res = mB - mA + 1;
        put(res);
    }
}
signed main(){ Main();return 0;}