#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){

  string s;
  ll k;
  cin >> s >> k;
  ll cnt = 0;
  ll res = 0;
  rep(i,s.size()-1){
    if(s[i] != s[i+1]){
      res += (cnt+1)/2;
      cnt = 0;
    }else{
      cnt++;
    }
  }
  res += (cnt+1)/2;
  res *= k;
  if(s == string(s.size(),s[0])){
    res = s.size()*k/2;
  }else{
    if(s[0] == s.back()){
      ll a = 1,b = 1;
      rep(i,s.size()-1){
        if(s[i+1] == s[i])a++;
        else break;
      }
      for(int i = s.size()-1;i > 0;i--){
        if(s[i-1] == s[i])b++;
        else break;
      }
      res -= (a/2+b/2-(a+b)/2)*(k-1);
    }
  }
  cout << res << endl;





  return 0;
}