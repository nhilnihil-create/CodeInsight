#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

bool fc(int i, const string &s){
  string is;
  while(i != 0){
    is.push_back(i%10 + '0');
    i /= 10;
  }
  rep2(i, is.size(), 3) is.push_back('0');
  reverse(ALL(is));
  // cerr << is << endl;
  int index = 0;
  rep(i, s.size()){
    if(s.at(i) == is.at(index)){
      index++;
      if(index == 3) break;
    }
  }
  return index == 3;
}

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  rep(i, 1000){
    if(fc(i, s) == true) ans++;
  }
  cout << ans << endl;
  return 0;
}