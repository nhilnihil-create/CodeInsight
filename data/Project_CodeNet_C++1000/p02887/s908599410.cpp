#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int cnt = 1;
  for(int i = 0; i < n-1; i++){
    if(s[i] == s[i+1]) continue;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}