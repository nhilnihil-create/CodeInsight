#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    ll ans = 0; ll soul = 1;
    for(int j=1;j<=65;++j){
        ll count_e = 0,count_o = 0;
        for(int i=0;i<n;++i){
            if(a[i]&1)count_o++;
            else count_e++;
            a[i] = (a[i]>>1);
        }
        ll pettu = (count_o*count_e)%mod;
        ans = (ans + pettu*soul)%mod;
        soul = (soul*2LL)%mod;
    }
    cout<<ans;

}