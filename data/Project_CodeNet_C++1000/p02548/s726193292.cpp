#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n; cin >>n;
  ll cnt = 0;
  for(int i = 1; i<=n; i++){
    cnt += (n-1)/i;
  }
  cout << cnt << endl;
  return 0;
}