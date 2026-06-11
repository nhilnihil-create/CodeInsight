#include<bits/stdc++.h>
 
using namespace std;
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long , long long>
#define pb push_back
#define ll long long
#define ld long double
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define fill(a,b) memset((a),(b),sizeof((a)))
#define FAST ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
ll power(ll x,ll y,ll m){ll r=1;for(;y;y>>=1){if(y&1)r=r*x%m;x=x*x%m;}return r;}
const ll mod = 1e9 + 7;
 
int run_test(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n + 1], b[m + 1];
    a[0] = b[0] = 0;
    ll sum = 0;
    for(int i=1; i<=n; i++){
        ll t;
        cin >> t;
        sum += t;
        a[i] = sum;
    }    
    sum = 0;
    for(int i=1; i<=m; i++){
        ll t;
        cin >> t;
        sum += t;
        b[i] = sum;
    }
    int ans  = 0;
    for(int i=0; i<=n; i++){
        if(k - a[i] >= 0){
            int  j = lower_bound(b,b + m, k - a[i]) - b;
            if(j > m || b[j] > k - a[i]){
                j--;
            }
            ans = max(ans, i + j);
        }
    }
    cout << ans;
    return 0;
}
 
int main(){
    FAST;
    ll t;
    t = 1;
 
    while(t--){
        run_test();
    }
}