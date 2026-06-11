#include <iostream>
using namespace std;
typedef long long ll;
ll dp[35];
int main(void){
    dp[0]=1;
   for(int i=0;i<=30;i++){
       dp[i+1]+=dp[i];
       dp[i+2]+=dp[i];
       dp[i+3]+=dp[i];
       dp[i]=(dp[i]+9)/10;
   }
    while(1){
        int n;
        cin>>n;
        if(n==0)break;
        cout<<(dp[n]+364)/365<<endl;
    }
}

