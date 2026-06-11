#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n; cin >>n;
  vector<string> s(n);
  rep(i,n) cin >>s[i];
  sort(s.begin(), s.end());
  int cnt = 1;
  for(int i = 1; i<n; i++){
    if(s[i]!=s[i-1]) cnt++;
  }
  cout << cnt << endl;
  return 0; 
}
