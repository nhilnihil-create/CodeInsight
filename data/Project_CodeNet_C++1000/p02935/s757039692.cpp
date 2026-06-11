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
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    sort(all(v));

    ld ans = v[0];
    rep(i, n-1) {
        ans = (ans + v[i+1]) / 2;
    }
    
    printf("%.8Lf\n", ans);

    return 0;
}