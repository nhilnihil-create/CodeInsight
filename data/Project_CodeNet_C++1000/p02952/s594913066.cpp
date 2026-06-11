#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 1; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;

  int ans = 0;
  int a = 1;
  rep(i, n+1){
    int a = i;
    int count = 0;
    while(a != 0) { a /= 10; count++; }
    if ((count % 2) == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}