#include<bits/stdc++.h>
using namespace std;
long long int dp[200][200],a,su[200];
int main(){
    cin>>a;
    for(int i=0;i<a;i++){cin>>su[i];}
    dp[su[0]][0]=1;
    for(int i=0;i<a-1;i++){
        for(int j=0;j<21;j++){
            if(dp[j][i]!=0){
                if(j+su[i+1]>20){}else{ dp[j+su[i+1]][i+1]+=dp[j][i]; }
                if(j-su[i+1]<0){}else{ dp[j-su[i+1]][i+1]+=dp[j][i]; }
                }
            }
        }
    cout<<dp[su[a-1]][a-2]<<endl;
    return 0;
}