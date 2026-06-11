#include <iostream>
using namespace std;
int n,dp[10][10],dp2[10][10],ans;
string s;
int f(int x){
    while(x>9)x/=10;
    return x;
}
int f2(int x){
    return x%10;
}
int main(void){
    cin>>n;
    for(int i=1;i<=n;i++){
        //cout<<f(i)<<" "<<f2(i)<<endl;
        dp[f(i)][f2(i)]++;
        dp2[f2(i)][f(i)]++;
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans+=dp[i][j]*dp2[i][j];
        }
    }
    cout<<ans<<endl;
}
