#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const ll mod=998244353;
//head
ll modpow(ll a, ll b, ll m) {
    if(b == 0) return 1 % m;
    ll u = modpow(a,b/2,m);
    u = (u*u)%m;
    if(b%2 == 1) {
        u = (u*a)%m;
    }
    return u;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vll occ(n,0);
    ll a;
    cin >> a;
    if(a != 0) {
        cout << 0 << endl;
        return 0;
    }
    occ[0]++;
    for(int i = 0; i < n - 1; i++) {
        cin >> a;
        occ[a]++;
    }
    if(occ[0] != 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(ll i = 1; i < n - 1; i++) {
        if(occ[i - 1] == 0 && occ[i] != 0) {
            ans = 0;
        }
        ans *= modpow(occ[i-1],occ[i],mod);
        ans %= mod;
    }
    cout << ans % mod << endl;
    return 0;
}
