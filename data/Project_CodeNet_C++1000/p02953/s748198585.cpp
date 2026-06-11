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
   int rep=-1;
   bool f=true;
   rep(i,n){
      if(rep<=a[i]-1){
         rep=a[i]-1;
      }
      else if(rep==a[i]){
         rep=a[i];
      }
      else{
         f=false;
         break;
      }
   }
   f? cout<<"Yes":cout<<"No";
   return 0;
}
