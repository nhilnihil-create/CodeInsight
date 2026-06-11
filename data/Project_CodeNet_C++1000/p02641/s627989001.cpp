#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main(){
  int x, n;
  cin >> x >> n;
  vector<int> p(102);
  rep(i,n){
    int a;
    cin >> a;
    p[a] = 1;
  }
  int dist = 10000;
  int ans = -1;
  rep(i,102){
    if(p[i] == 1) continue;
    int t = abs(x - i);
    if(t < dist){
      ans = i;
      dist = t;
    }
  }
  cout << ans << endl;
  return 0;
}