#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
int main(){
  string s;
  cin >> s;
  ll k;
  cin >> k;
  if( count(s.begin(),s.end(),s[0]) == s.size() ){
    cout << s.size()*k/2 << "\n";
    return 0;
  }
  auto func = [&]( string st ){
    ll cnt = 0;
    ll ren = 1;
    for(ll i=1;i<st.size();++i){
      if( st.at(i) == st.at(i-1) ){
        if( i != st.size()-1 ){
          ren++;
        }else{
          ren++;
          cnt += ren/2;
        }
      }else{
        cnt += ren/2;
        ren = 1;
      }
    }
    return cnt;
  };
  
  if( s.front() != s.back() ){
    cout << func(s)*k << "\n";
    return 0;
  }else{
    cout << func(s) + (func(s+s)-func(s))*(k-1) << "\n";
  }
  return 0;
}