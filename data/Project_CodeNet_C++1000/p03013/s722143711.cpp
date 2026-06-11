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
   int n,m;
   cin>>n>>m;
   vector<ll> b(n+10);
   vector<ll> a(n+10,0);

   rep(i,m){
      int x;
      cin>>x;
      a[x]=1;
   }
   b[0]=1;
   b[1]=1; 
   if(a[1]!=0){
      b[1]=0;
   }

   for(int i=2;i<=n;i++){
      b[i]=b[i-1]+b[i-2];
      if(a[i]!=0){
         b[i]=0;
      }
      b[i]=b[i]%1000000007;
   }
   cout<<b[n]<<endl;
   
   return 0;
}
