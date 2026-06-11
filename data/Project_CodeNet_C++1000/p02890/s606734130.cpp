#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

int main(){
    int n;
    cin>>n;
    int cnt[n]={};
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt[a-1]++;
    }
    ll sum1[n+1]={};
    ll sum2[n+2]={};
    for(int i=0;i<n;i++){
        sum1[cnt[i]]++;
        sum2[cnt[i]]++;
    }
    for(int i=0;i<=n;i++){
        sum1[i]*=i;
    }
    for(int i=1;i<=n;i++){
        sum1[i]+=sum1[i-1];
    }
    for(int i=n-1;i>=0;i--){
        sum2[i]+=sum2[i+1];
    }
    ll ans=n;
    for(int k=1;k<=n;k++){
        while(ans>0){
            ll f=sum1[ans]/ans+sum2[ans+1];
            if(k<=f){
                cout<<ans<<endl;
                break;
            }
            else{
                --ans;
            }
        }
        if(ans==0){
            cout<<0<<endl;
        }
    }
}
