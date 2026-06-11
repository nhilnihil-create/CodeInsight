#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define all(x) (x).begin() , (x).end()
#define f first
#define s second
#define pr(x) cout<<x<<endl;
#define pr2(x,y) cout<<x<<" "<<y<<endl;
#define pr3(x,y,z) cout<<x<<" "<<y<<endl;
#define prv(v) for(auto x:v) cout<<x<<" ";
using namespace std;
 
const ll N =(1e5+5);
const ll MOD = 1e9+7;
const ll INF = 1e16;
const ll LOG = 29;

long long binpow(long long a, long long b) {
     a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD ;
        a = (a * a)%MOD ;

        
        b >>= 1;
    }
    res%=MOD;
    return res;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    for(int i =1;i<=n;i++){
        cin>>a[i];
    }
    ll ans = 0;
    ll ans2 = 0;
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            if(a[i] > a[j]){
                ans2++;
               if(i<j) ans++;
            }
        }
        
    }
    ans = (ans*k)%MOD;
    if(ans<0)ans+=MOD;
    ll gg = k*(k-1);gg/=2ll;
    gg%=MOD;
    
    ans2 = (ans2 * gg)%MOD;
    if(ans2<0)ans2+=MOD;
    ans2%=MOD;
    ans = (ans+ans2)%MOD;
    if(ans<0)ans+=MOD;
    ans%=MOD;   
    cout<<ans<<endl;
}



int main()
{
    ios_base::sync_with_stdio(0);
     cin.tie(NULL);
     
    ll t=1;
    while(t--){
        solve();
    }
     
 
 
    return 0;     
    
        
}