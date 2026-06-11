#include<iostream>
#define ll long long
using namespace std;
ll sum[2005];
//ll f[2005];
constexpr auto mod=1000000000+7;
int main(){
    int n;
    cin>>n;
    //f[1]=f[2]=0;
   // f[3]=f[4]=f[5]=1;
    sum[3]=1,sum[4]=2;sum[5]=3;
    for(int i=6;i<=n;i++){
        sum[i]=(sum[i-1]+sum[i-3]+1+mod)%mod;
    }
    cout<<(sum[n]+mod-sum[n-1])%mod<<endl;
    //getchar();
    //getchar();
    return 0;
}