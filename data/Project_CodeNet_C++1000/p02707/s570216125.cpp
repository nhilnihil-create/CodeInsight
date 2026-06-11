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
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n-1);
    rep(i, n-1) cin >> a[i];
    vector<int> cnt(n);
    rep(i, n-1) {
        cnt[a[i]-1]++;
    }
    rep(i, n) {
        put(cnt[i])
    }
    return 0;
}