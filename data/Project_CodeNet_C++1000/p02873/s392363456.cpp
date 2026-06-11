#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
const ll INF = 999999999999999;

int main(){
  string s;
  cin >> s;
  vector<ll> num(s.size()+1,0);
  for(ll i=0;i<s.size();++i){
    if( s.at(i) == '<' ) num.at(i+1) = max(num.at(i+1),num.at(i)+1);
  }
  for(ll i=s.size()-1;i>=0;--i){
    if( s.at(i) == '>' ) num.at(i) = max(num.at(i),num.at(i+1)+1);
  }
  ll ans = 0;
  rep(i,num.size()) ans += num.at(i);
  
 /* rep(i,s.size()){
    cout << num.at(i) << " " << s.at(i) << " ";
  }
  cout << num.back() << endl;*/
  
  cout << ans << endl;
    
  return 0;
}