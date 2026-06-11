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
    ll n, k ;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    if (n <= k) {
        put(0);
        return 0;
    }

    sort(all(h));

    ll sum = 0;
    rep(i, h.size() - k) sum += h[i];
    put(sum);
    
    return 0;
}