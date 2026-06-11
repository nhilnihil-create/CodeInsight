#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"APPROVED":"DENIED")<<endl;
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
    
    bool ok = true;
    rep (i, n) {
        if (a[i] % 2 == 0) {
            if (a[i] % 3 == 0 || a[i] % 5 == 0) {

            }
            else {
                ok = false;
                break;
            }
        }
    }
    yorn(ok);


    return 0;
}