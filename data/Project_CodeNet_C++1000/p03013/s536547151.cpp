#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    rep(i, m) cin >> a[i];
    
    vector<ll> A(n+1);
    rep(i, m) A[a[i]] = -1;

    A[0] = 1;
    A[1] = A[1] < 0 ? -1 : 1;

    ll MOD = 1000000007;

    for (int i = 2; i <= n; i++) {
        if (A[i] < 0) {
            // if (i > n - 12) {
            //     cout << A[i] << endl;
            // }
            continue;
        }
        if (A[i - 1] >= 0) A[i] += A[i - 1] % MOD;
        if (A[i - 2] >= 0) A[i] += A[i - 2] % MOD;
        A[i] %= MOD;
        // if (i > n - 12) {
        //     cout << A[i] << endl;
        // }
    }

    put(A[n]);
    

    return 0;
}