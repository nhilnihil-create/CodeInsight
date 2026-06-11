#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,ans = 0;
  cin >> N;
  rep(i,N+1){
    if(i == 0){
      continue;
    }
    else if(i < 10){
      ans++;
    }
    else if(i > 99 && i < 1000){
      ans++;
    }
    else if(i > 9999 && i < 100000){
      ans++;
    }
  }
  cout << ans;
}