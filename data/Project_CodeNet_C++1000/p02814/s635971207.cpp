#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

ll gcd(ll a, ll b){
    ll r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

ll a[100010];

int main(){
    int n;
    ll m;
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, n) a[i] /= 2;

    ll l = 1;
    rep(i, n) l = lcm(l, a[i]);

    bool flag = true;
    rep(i, n) flag &= ((l/a[i])%2!=0);
    if (!flag){
        cout << 0 << endl;
        return 0;
    }
    
    ll num = m / l;
    cout << (num + 1) / 2 << endl;

    return 0;
}