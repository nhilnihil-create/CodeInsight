#include <bits/stdc++.h>
#define maxn 100001
#define maxa 2000005
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define piii pair<pii, ll>
#define ft first
#define sd second
#define pb push_back
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define repr(i, a, n) for(ll i = n-1; i >= a; i--)
#define mem(a, b) memset(a, b, sizeof(a))
#define sort(v) sort(v.begin(), v.end())

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
ll ceil(ll a, ll b){ return (a+ b-1)/b; }
void flaged(bool flag){
    if(flag) cout << "Yes\n";
    else cout << "No\n";
}
// power and modulo inverse
ll power(ll a, ll b = MOD-2){
    if(b == 0) return 1;
    ll r = power(a, b/2);
    r = (r*r)%MOD;
    if(b%2 == 1) r = (r*a)%MOD;
    return r;
}
// factorial
ll fact[maxa], finv[maxa];
void calf(){
    fact[0] = finv[0] = 1;
    for(ll i = 1; i < maxa; i++){fact[i] = (fact[i-1]*i) %MOD;finv[i] = (finv[i-1]*power(i))%MOD;}
}
// nCr
ll ncr(ll N, ll R){ if(R > N) return 0; return (fact[N]*((finv[R]*finv[N-R])%MOD))%MOD;}

void solve(){
    /*ll n, k;
    cin >> n >> k;
    ll a[n];
    ll z = 0, p = 0;
    vector<ll> neg, pos;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) z++;
        else if(a[i] < 0) {
            neg.pb(a[i]);
        }
        else {
            p++; pos.pb(a[i]);
        }
    }n -= (z+p);
    ll total = n+p+z;
    ll ns = n*p, ps = (p*(p-1))/2 + (n*(n-1))/2;
    ll zs = ((total-1)*total)/2 - ns-ps; cout << zs << " " << ns << " " << ps << endl;
    if(k <= ns){

    }
    else if( k > ns && k <= ns + zs){cout << "0";}
    else{

    }*/

    ll n, d ,a;
    cin >> n >> d >> a;
    vector<pii> v;
    rep(i, 0, n)
    {
        ll x, y; cin >> x >> y; v.pb({x, y});
    }
    sort(v);
    ll c[n+1]; mem(c, 0);
    ll ans = 0;
    for(ll i = 0, j = 0; i < n; i++){
        while(j < n && v[j].ft - v[i].ft <= 2*d) j++;
        ll con = max(0ll, ceil(v[i].sd - c[i]*a, a)); //cout << con << " ";
        ans += con;  
        c[i] += con;
        c[j] -= con;
        c[i+1] += c[i];
    }
    cout << ans;

}

int main()
{
    fast();
    ll t = 1;//cin >> t;
    while(t--){
        solve();
    }
}
