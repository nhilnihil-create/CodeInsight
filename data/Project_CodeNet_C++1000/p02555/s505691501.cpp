#include <bits/stdc++.h>
using namespace std;
#define int long long



struct listnode{
 int val;
 listnode*  next;};
 vector<int> func( vector<int> a,vector<int>l,int sum){
      vector<int>k,val;
       for(int i=0;i<l.size();i++)
           if(l[i]==0){
            k.push_back(i);
            val.push_back(a[i]);}
   if(sum<0)
   return a;
  else {
      sort(val.rbegin(),val.rend());
      for(int i=0;i<k.size();i++)
         a[k[i]]=val[i];}
         return a;

 }
 


int32_t main(){
 int m=1000000007;
 
     int n;
     cin>>n;
    int dp[2001];
dp[0] = 1; 
dp[1] = 0; 
dp[2] = 0; 
dp[3] = 1; 
dp[4] = 1; 
dp[5] = 1; 
dp[6] = 2;
dp[7] = 3;
for(int i=8;i<n+1;i++)
dp[i]=(dp[i-3]+dp[i-1])%m;
cout<<dp[n]%m<<endl;
return 0;
}