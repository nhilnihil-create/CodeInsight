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
   double w,h,x,y;
   cin>>w>>h>>x>>y;

   double cx=w/2;
   double cy=h/2;
   bool f=false;
   if(cx==x && cy==y) f=true;
   cout<<std::setprecision(10)<<double(w)*double(h)/2;
   cout<<" ";
   f? cout<<1:cout<<0;
   return 0;
}
