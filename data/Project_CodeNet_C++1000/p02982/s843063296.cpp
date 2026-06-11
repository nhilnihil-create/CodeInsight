#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> x(n * d);
    rep(i, n * d) cin >> x[i];
    
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ll diff = 0;
            rep(k, d) {
                ll dx = x[d * i + k] - x[d * j + k];
                diff += dx * dx;
            }
            int sq = (int)sqrt(diff);
            if (sq * sq == diff) {
                c += 1;
            }
        }
    }
    put(c)

    return 0;
}