#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using ll = long long;
#define ull unsigned ll
#define endl "\n"
#define vi vector<int>
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()
#define mst(a,b) memset(a,b,sizeof(a))
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int, pii>
#define mt make_tuple
#define eb emplace_back
using namespace std;

const ll N = 1e5 + 5, mod = 1e9 + 7;
const ll inf = 1e9;

bool P(const pair<ll, ll> &a, const pair<ll, ll> &b){
    if(a.F == b.F) return a.S < b.S;
    return a.F > b.F;
}

void solve(){
    ll n;
    cin >> n;
    vi a;
    for(ll i = 2; i * i <= n; i++){
        ll j = 0;
        while(n % i == 0){
            n = n / i;
            j++;
        }
        if(j > 0){
            a.pb(j);
        }
    }
    if(n > 1){
        a.pb(1);
    }
    ll ans = 0;
    for(ll i : a){
        ll j = 1;
        while(j * j + j <= 2ll * i){
            j++;
        }
        ans += j - 1;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);//cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t,p;
    t=1;
    //cin>>t;
    for(p=1;p<=t;p++){
        solve();
    }
    return 0;
}
