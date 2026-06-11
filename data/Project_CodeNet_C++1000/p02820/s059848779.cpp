#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, K;
    cin >> n >> K;

    ll R, S, P;
    cin >> R >> S >> P;

    string T;
    cin >> T;

    ll sum = 0;
    rep(i, n) {
        if (i >= K && T[i] == T[i-K]) {
            T[i] = '_';
            continue;
        }
        if (T[i] == 'r') {
            sum += P;
        }
        else if (T[i] == 's') {
            sum += R;
        }
        else {
            sum += S;
        }
    }

    put(sum);
}
signed main(){ Main();return 0;}