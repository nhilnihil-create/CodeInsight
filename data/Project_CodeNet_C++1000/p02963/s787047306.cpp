#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  ll s;
  cin>>s;
  ll a=1e9,b=1,c,d;
  if(s%a==0){
    d=s/a; c=0;
  }else{
    d=s/a+1; c=1e9-s%a;
  }
  cout<<0<<" "<<0<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}