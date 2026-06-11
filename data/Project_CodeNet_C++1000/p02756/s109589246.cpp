#include<bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
#define int long long

signed main(){
  string S;
  cin >> S;
  vector<char> right;
  vector<char> left;
  bool hanten = false;

  int Q;
  cin >> Q;

  rep(i,Q){
    int query;
    cin >> query;
    if(query == 1)hanten = !hanten;
    if(query == 2){
      int f;char c;
      cin >> f >> c;
      if(f == 1)if(hanten)right.push_back(c);else left.push_back(c);
      else if(hanten)left.push_back(c);else right.push_back(c);
    }
  }
  string ans;
  if(hanten){
    for(int i = right.size()-1;i >= 0;i--){
      ans += right[i];
    }
    for(int i = S.length()-1;i >= 0;i--){
      ans += S[i];
    }
    for(int i = 0;i < left.size();i++){
      ans += left[i];
    }
  }
  else{
    for(int i = left.size()-1;i >= 0;i--){
      ans += left[i];
    }
    for(int i = 0;i < S.length();i++){
      ans += S[i];
    }
    for(int i = 0;i < right.size();i++){
      ans += right[i];
    }
  }
  cout << ans;
}

