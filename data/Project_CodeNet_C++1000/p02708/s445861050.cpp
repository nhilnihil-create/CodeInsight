#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
const ll mod = 1e9+7;
int main(){
    ll n,k;
    cin>>n>>k;
    ll st = 0;
    ll en = n;
    ll sts = 0;
    ll sen = 0;
    ll ans = 1;
    for(int i=1;i<=n;i++){
        sts+=st;
        sen+=en;
        st++;
        en--;
        if(i>=k){
            ans+=(sen-sts+1ll);
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}
