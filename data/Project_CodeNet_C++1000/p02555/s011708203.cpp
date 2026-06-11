#include <iostream>
#include <cmath> 
using namespace std;
long long mod=1e9+7;
long long s,ans,res,c[2110][2110];
int main()
{
    cin>>s;
    c[1][1]=c[1][0]=1;
    for(int i=2;i<=2100;i++){
        c[i][0]=1;
        //cout<<1<<endl; 
        for(int j=1;j<=2100;j++){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    } 
    //cout<<1<<endl; 
    if(s==3)ans=1; 
    while(s>=3){
         s-=3;res++; 
         ans=(ans+c[s+res-1][res-1])%mod; //cout<<ans<<endl;
    } 
    cout<<ans<<endl; 
    //system("pause");
    return 0;
}
