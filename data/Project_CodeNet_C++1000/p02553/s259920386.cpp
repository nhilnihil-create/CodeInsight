#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ll MOD = 1000000007;
ll power(ll x,ll y){ll R=1;x%=MOD;while(y>0){if(y&1)R=(R*x)%MOD;y=y>>1,x=(x*x)%MOD;}return R;}

int main() 
{
    vector<ll> v;
    ll ans= LLONG_MIN;
    for(int i=0; i<4;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0; i<2;i++){
        for(int j=2;j<4;j++){
            ans=max(ans,v[i]*v[j]);
            
        }
    }
    cout<<ans<<endl;
}