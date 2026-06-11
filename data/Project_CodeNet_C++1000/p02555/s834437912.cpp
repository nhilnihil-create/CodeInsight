#include<iostream>
#include<math.h>
#include<algorithm>
typedef long long ll;
const ll mod=1e9+7;
using namespace std;
ll n,a,b;
ll dp[2010];
int main(){
cin>>n;
for (int i=3;i<10;i++)
dp[n-i]= 1;
dp[n]=1;
for (int i=n-3;i>=0;i--){
for (int j= 3;j<10;j++){
dp[i-j]=(dp[i-j+1]+dp[i])%mod;
}
}
cout<<dp[0];
return 0;
} 

