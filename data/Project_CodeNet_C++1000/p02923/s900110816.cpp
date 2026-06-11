#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define PI acos(-1)
typedef  long long ll;
ll gcd(ll x,ll y){
   if(y==0) return x;
   else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
   return x/gcd(x,y)*y;
}

int main(){
   int n;
   cin>>n;

   vector<int> a(n);
   rep(i,n){
      cin>>a[i];
   }
   int ans=0;
   int tmp=0;
   
   for(int i=0;i<n-1;i++){
      if(a[i]>=a[i+1]){
         tmp++;
      }
      else{
         tmp=0;
      }
      ans=max(ans,tmp);
   }
   cout<<ans;
   return 0;
}
