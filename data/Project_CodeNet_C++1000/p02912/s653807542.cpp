#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    priority_queue<ll, vector<ll>, less<ll>> que;
    rep(i, n) que.push(a[i]);
    
    ll sum = 0;
    rep(i, n) sum += a[i];
    
    rep(i, m) {
        ll p = que.top();
        que.pop();
        ll d = p - p / 2;
        p /= 2;
        que.push(p);
        sum -= d;
    }

    put(sum);
}
signed main(){ Main();return 0;}