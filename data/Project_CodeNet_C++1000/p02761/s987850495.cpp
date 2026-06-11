#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,m; cin >>n >>m;
  int s[6], c[6];
  rep(i,m) cin >>s[i] >>c[i];
  rep(i,1000){
    string str = to_string(i);
    if(str.size()==n){
      int cnt = 0;
      rep(j,m){
        if(str[s[j]-1]!=c[j]+'0') break;
        else cnt++;
      }
      if(cnt==m){
        cout << i << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0; 
}