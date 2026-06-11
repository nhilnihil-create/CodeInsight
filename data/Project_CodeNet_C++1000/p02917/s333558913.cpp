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

   vector<int> b(n+1);
   b[0]=100000000;
   b[n]=100000000;
   for(int i=1;i<n;i++){
      cin>>b[i];
   }
   ll ans=0;
   for(int i=1;i<=n;i++){
      int a=min(b[i-1],b[i]);
      ans+=a;
   }

   cout<<ans;
   return 0;
}
