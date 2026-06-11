#include <bits/stdc++.h>

#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

#define MOD 1000000007
#define INF 1000000000

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(b <= 0) return -1;
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    return (a/gcd(a,b)*b);
}

int main() {
    ll N,M; cin >> N >> M;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    rep(i,N) a[i] /= 2;

    vector<ll> b = a;
    bool flag = true;
    while(flag){
        flag = (b[0]%2 == 0);
        rep(i,N){
            if((b[i]%2 == 0) == !flag){
                cout << 0;
                return 0;
            }
            b[i] /= 2;
        }
    }

    ll lcmmin = a[0];
    rep(i,N-1){
        lcmmin = lcm(lcmmin, a[i+1]);
        if(lcmmin > M){
            cout << 0;
            return 0;
        }
    }

    ll ans = (M + lcmmin)/(lcmmin*2);
    cout << ans << endl;
    return 0;
}
