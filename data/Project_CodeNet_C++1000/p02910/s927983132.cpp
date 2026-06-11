#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
int main(){
  string str;
  ll x=0;
  cin>>str;
  for(ll i=0;i<(ll)str.size();i++){
    if(i%2==0 && str.at(i)=='L'){x++;}
    if(i%2==1 && str.at(i)=='R'){x++;}
  }
  if(x>0){cout<<"No"<<endl;}
  else{cout<<"Yes"<<endl;}
}