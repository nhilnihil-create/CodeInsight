#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = ll(1e12);
const ll mod = ll(1e9+7);
const double pi = acos(-1);
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define pf(x) cout << (x) << endl
#define all(x) (x).begin(),(x).end()
#define yes pf("Yes")
#define no pf("No")
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll factorial(ll n){
    ll ans = 1;
    rep1(i, n){
        ans *= i;
        ans %= mod;
    }
    return ans;
}

ll power(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b) {
        if(b & 1LL) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}

//modの値の確認をすること
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    rep0(i, n){
        cin >> a[i];
        ans += abs(a[i]);
    }
    sort(all(a),greater<>());
    if(a[0] >= 0 && a[n - 1] < 0){
        pf(ans);
        ll i = 1;
        while (a[i] >= 0) {
            cout << a[n - 1] << " " << a[i] << endl;
            a[n - 1] -= a[i];
            ++i;
        }
        cout << a[0] << " " << a[i] << endl;
        ll m = a[0] - a[i];
        nfor(j, i + 1, n){
            cout << m << " " << a[j] << endl;
            m -= a[j];
        }
        
    }else if(a[n - 1] >= 0){
        pf(ans - a[n - 1] * 2);
        cout << a[n - 1] << " " << a[n - 2] << endl;
        ll m = a[n - 1] - a[n - 2];
        rep0(i, n - 3){
            cout << m << " " << a[i] << endl;
            m -= a[i];
        }
        if(n != 2)cout << a[n - 3] << " " << m << endl;
    }else{
        pf(ans + a[0] * 2);
        cout << a[0] << " " << a[1] << endl;
        ll m = a[0] - a[1];
        nfor(i, 2, n){
            cout << m << " " << a[i] << endl;
            m -= a[i];
        }
    }
    return 0;
}
