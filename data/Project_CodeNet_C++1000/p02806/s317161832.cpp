#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
int main(){
  ll N,a=0;
  cin>>N;
  vector<string> s(N);
  vector<ll> t(N);
  for(ll i=0;i<N;i++){
    cin>>s.at(i)>>t.at(i);
    a+=t.at(i);
  }
  string str;
  cin>>str;
  ll rock=0;
  for(ll i=0;i<N;i++){
    rock+=t.at(i);
    if(str==s.at(i)){
      cout<<a-rock<<endl;
      return 0;
    }
  }
}