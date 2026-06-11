#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll=long long;
typedef pair<int,int> P;
const int MOD=1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> sum(64);
    vector<ll> dat(n);
    rep(i,n){
        cin>>dat[i];
        rep(j,60){
            if((dat[i]>>j)&1) sum[j]++;
        }
    }
    ll now=n,num=1;
    ll ans=0;
    rep(i,60){
        n=now;
        if(i!=0) num*=2;
        num%=MOD;
        rep(j,now-1){
            if((dat[j]>>i)&1){
                sum[i]--;
                n--;
                ans+=num*(n-sum[i])%MOD;
            }
            else{
                n--;
                ans+=num*(sum[i])%MOD;
            }
            ans%=MOD;
        }
    }
    cout<<ans<<endl;
}