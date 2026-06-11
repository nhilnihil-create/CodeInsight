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
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, K;
    cin >> n >> K;

    vector<ll> A(n);
    rep(i, n) {
        cin >> A[i];
        A[i] *= 1000;
    }

    ll left = 0, right = 1e12+1;
    // left: 着る回数がKよりおおきくなる最大の長さ
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        
        ll sum = 0;
        rep(i, n) {
            ll cnt = (ll)((A[i]-1) / mid);
            sum += cnt;
        }

        if (sum > K) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    ll res = (right + 999) / 1000;
    put(res);

}
signed main(){ Main();return 0;}