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
  ll n,a,b;
  cin>>n>>a>>b;

  ll c=a%2;
  ll d=b%2;

  if(c==d){
     cout<<(b-a)/2;
  }
  else{
     cout<<min(a-1,n-b)+1+(b-a-1)/2;
  }

return 0;
}
