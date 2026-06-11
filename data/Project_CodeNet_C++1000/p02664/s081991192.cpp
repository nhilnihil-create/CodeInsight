#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
int main(){
  string str;
  cin>>str;
  for(ll i=0;i<(ll)str.size();i++){
    if(str.at(i)=='?'){str.at(i)='D';}
  }
  cout<<str<<endl;
}