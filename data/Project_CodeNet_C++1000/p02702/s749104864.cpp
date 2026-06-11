#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());
  
  vector<int> v(n,0);
  int x = 1;
  
  for(int i = 0; i < n; i++){
    if(i == 0) v[i] = s[i]-'0';
    else v[i] = v[i-1] + ((s[i]-'0')*x);
    v[i] = v[i] % 2019;
    x *= 10;
    x %= 2019;
  }
  
  int ans = 0;
  vector<int> count(2100,0);
  count[0] = 1;

  for(int i = 0; i < n; i++){
    if(count[v[i]] == 0){
      count[v[i]] = 1;
    }else{
      ans += count[v[i]];
      count[v[i]]++;
    }
  }
  
  cout << ans << endl;

  return 0;
}