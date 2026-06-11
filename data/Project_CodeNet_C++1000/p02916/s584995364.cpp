#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    vector<int> c(n-1);
    rep(i, n-1) cin >> c[i];

    ll sum = 0;
    int prev = -1;
    rep(i, n) {
        sum += b[a[i] - 1];
        if (prev >= 0 && a[i] - prev == 1) {
            sum += c[prev - 1];
        }
        prev = a[i];
    }

    put(sum)

    return 0;
}