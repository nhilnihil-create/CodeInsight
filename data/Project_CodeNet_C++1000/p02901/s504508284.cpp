#include <iostream>
using namespace std;
int n,m,a,b,c,dp[(1<<12)],L;
int main(void){
    for(int i=1;i<(1<<12);i++)dp[i]=1e9;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        L=0;
        for(int j=0;j<b;j++){
            cin>>c;
            c--;
            L|=(1<<c);
        }
        for(int i=0;i<(1<<n);i++){
            dp[i|L]=min(dp[i|L],dp[i]+a);
            //cout<<dp[i]<<" "<<a<<endl;
        }
    }
    if(dp[(1<<n)-1]==1e9)cout<<-1<<endl;
    else cout<<dp[(1<<n)-1]<<endl;
}
