#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int mod = 1000000007;

int pow(int a, int b){
    long long c=1;
    rep(i,b){
        c*=a;
        c=c%mod;
    }
    return c;
}

int main() {
    int N,K;
    cin>>N>>K;
    ll ans = 0;
    vector<ll> kazu(K+1);
    vector<ll> ruizyou(K+1,-1);
    ll num;
    for(int i=K;i>0;i--){
        int syurui=K/i;
        if(ruizyou[syurui]==-1){
            num = pow(syurui,N);
            ruizyou[syurui]=num;
        }else{
            num = ruizyou[syurui];
        }

        if(syurui>=2){
            for(int j=2;j<syurui+1;j++){
                num-=kazu[i*j];
                if(num<0) num+=mod;
            }
        }
        kazu[i]=num;
        ans+=num*i;
        ans=ans%mod;
    }
    cout << ans << endl;
}