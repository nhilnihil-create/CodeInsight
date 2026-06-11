#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,ans1=1,ans2=1,ans3=1,ans4=1,ans,mod=1e9+7;
    cin>>n;
    for(int i=0;i<n;i++){
        ans1*=10;
        ans2*=9;
        ans3*=9;
        ans4*=8;
        ans1%=mod;
        ans2%=mod;
        ans3%=mod;
        ans4%=mod;
    }
    ans=(ans1-ans2-ans3+ans4)%mod;
    if(ans<0){
        ans+=mod;
    }
    cout<<ans<<endl;
    return (0);
}