#include <bits/stdc++.h>
#define ll long long int
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
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    rep(i, n) a[i] = a[i] % k;
    sort(all(a));

    int best = 0;
    rep(i, n) {
        int d = 0;
        if (i == n -1) {
            d = k + a[0] - a[n-1];
        }
        else {
            d = a[i+1] - a[i];
        }
        best = max(best, d);
    }
    put(k - best);

    return 0;
}