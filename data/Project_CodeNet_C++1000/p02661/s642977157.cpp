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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<int, pii>
#define mt make_tuple
#define eb emplace_back
using namespace std;

const ll N = 2e5 + 5, mod = 1e9 + 7;
const int inf = 1e9;

ll power(ll x, ll p){
    ll r = 1ll;
    x = x % mod;
    while(p > 0){
        if(p & 1) r = (r * x) % mod;
        p = p >> 1;
        x = (x * x) % mod;
    }
    return r;
}

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    sort(all(a));
    sort(all(b));
    if(n % 2 == 1){
        cout << b[n/2] - a[n/2] + 1 << endl;
        return;
    }
    cout << b[n/2] + b[(n-1)/2] - a[n/2] - a[(n-1)/2] + 1 << endl;
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
        //cout << power(2, 5);
        solve();
    }
    return 0;
}
