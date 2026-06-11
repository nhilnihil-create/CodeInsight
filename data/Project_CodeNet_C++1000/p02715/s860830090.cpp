#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
ll mod_pow(int x,int y){//x^yを返す//計算量は0(log(y))
    ll tmp=x,res=1;
    while(y){
        if(y%2){
            res=res*tmp%MOD;
        }
        y>>=1;
        tmp=tmp*tmp%MOD;
    }
    return res;
}
int main(){
    int N,K;
    cin>>N>>K;
    unordered_map<int,ll> mp;
    for(int i=K;i>=1;i--){
        if(2*i>K){mp[i]=1;}
        else{
            int a=mod_pow(K/i,N);
            for(int j=2*i;j<=K;j+=i){
                a-=mp[j]-MOD;
                a%=MOD;
            }
            mp[i]=a;
        }
    }
    ll ans=0;
    for(int i=1;i<=K;i++){
        ans+=mp[i]*i;
        ans%=MOD;
    }
    cout<<ans<<endl;
}