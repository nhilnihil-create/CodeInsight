#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
#define ll long long
#define ld long double
#define ALL(x) begin(x),end(x)

int main() {
  ll n;
  cin >> n;
  //tupleじゃなくてpairでおｋ、書き換えるの面倒くさい
  vector<tuple<string,ll,ll>> s(n);
  rep(i,n){
    string st; ll nt;
    cin >> st >> nt;
    s.emplace_back(st,nt,i);
  }
  string p;
  cin >> p;
  
  bool flag = false;
  ll ans = 0;
  for(auto &x : s){
    //cout << get<0>(x) << endl; //string取得
    if(flag){
      ans += get<1>(x);
    }else{
      if(get<0>(x) == p) flag = true;
    }
  }
  cout << ans << endl;
}