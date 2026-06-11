#include <bits/stdc++.h>
using namespace std;
int h[100010], maxv[100010];
int main(){
  int a, b;
  cin >> a >> b;
  for(int i = 0;i < a;i++)
  {
    cin >> h[i];
  }
  for(int i = 0;i < b;i++){
    int x, y;
    cin >> x >> y;
    maxv[x - 1] = max(h[y - 1], maxv[x - 1]);
    maxv[y - 1] = max(h[x - 1], maxv[y - 1]);
  }
  int ans = 0;
  for(int i = 0;i < a;i++)
  {
    ans += h[i] > maxv[i];
  }
  cout << ans;
  return 0;
}