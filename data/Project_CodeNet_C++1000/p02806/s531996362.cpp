#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<string, int>> a(n);
  string s;
  for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  cin >> s;
  int ans = 0;
  bool flag = false;
  for(int i = 0; i < n; i++){
    if(flag) ans += a[i].second;
    if(a[i].first == s) flag = true;
  }
  cout << ans << endl;
}