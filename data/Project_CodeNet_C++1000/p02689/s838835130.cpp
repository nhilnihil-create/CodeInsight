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
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    
    vector<int> ma(n);
    rep(i, m) {
        ma[a[i]-1] = max(ma[a[i]-1], h[b[i]-1]);
        ma[b[i]-1] = max(ma[b[i]-1], h[a[i]-1]);
    }
    int cnt = 0;
    rep(i, n) {
        if (h[i] > ma[i]) {
            cnt++;
        }
    }

    put(cnt);
    return 0;
}