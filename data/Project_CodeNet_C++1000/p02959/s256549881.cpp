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
    int n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i, n+1) cin >> a[i];

    vector<ll> b(n);
    rep(i, n) cin >> b[i];
    
    ll sum = 0;
    rep(i, n) {
        int v1 = min(a[i], b[i]);
        a[i] -= v1;
        b[i] -= v1;
        int v2 = min(a[i+1], b[i]);
        a[i + 1] -= v2;
        b[i] -= v2;
        sum += v1 + v2;
    }

    put(sum);

    return 0;
}