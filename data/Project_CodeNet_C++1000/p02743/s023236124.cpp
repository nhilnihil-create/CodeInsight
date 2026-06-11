#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  ll x=(c-a-b);
  if(x<=0){cout<<"No"<<endl;return 0;}
  x*=x;
  ll y=4*a*b;
  //cout<<x-y<<endl;
  if(y<x){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
}