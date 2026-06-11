#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  int n,l;
  cin >> n >> l;
  int total = 0;
  int tmp = 0;
  for(int i = 1; i < n+1; i++) {
    total += l + i - 1;
  }
  int minNum = 1000;
  int ans = 0;
  for (int i = 1; i < n+1; i++) {
    if (abs((total - (l + i-1)) - total) < minNum) {
      minNum = abs((total - (l+i-1)) - total);
      ans = total - (l+i-1);
    }
  }
  cout << ans << endl;
}
