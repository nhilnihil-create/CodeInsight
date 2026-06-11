#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  int n = s.size(), num = 0;
  vector<int> ans(n+1,0);
  for(int i=0; i<n; ++i){
    if(s[i] == '<') ans[i] = 0;
    while(s[i] == '<'){
      ++i;
      ans[i] = ans[i-1] +1;
    }
  }
  for(int i=n-1; i>=0; --i){
    if(s[i] == '>') ans[i+1] = 0;
    while(s[i] == '>'){
      ans[i] = max(ans[i], ans[i+1] +1);
      --i;
    }
  }
  ll tot = 0;
  for(int i=0; i<n+1; ++i) tot += ans[i];
  cout << tot << endl;
}