/* 
* ID: juryc
* PROG: Ibis vs monster
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int h; cin>>h; int n; cin>>n;
vector<int> a(n),b(n);
for(int i=0;i<n;i++) cin>>a[i]>>b[i]; 
vector<int> dp(h+1,0x3f3f3f3f); 
dp[0]=0;
for(int i=1;i<=h;i++){
for(int j=0;j<n;j++){
if(a[j]>i){dp[i]=min(dp[i],b[j]); }
else dp[i]=min(dp[i],dp[i-a[j]]+b[j]);
}
}
cout<<dp[h]<<"\n";
return 0;
} 