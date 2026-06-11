#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  ll x=max(a,b);
  if(c%x==0){cout<<c/x<<endl;}
  else{cout<<c/x+1<<endl;}
}