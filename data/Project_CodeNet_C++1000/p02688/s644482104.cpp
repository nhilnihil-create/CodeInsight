#include <bits/stdc++.h>
using namespace std;
bool victims[11000];
int main(){
  int a, b;
  cin >> a >> b;
  for(int i = 0;i < a;i++)
  {
   victims[i] = false;
  }
  for(int i = 0;i < b;i++)
  {
    int re;
    cin >> re;
    for(int j = 0;j < re;j++)
    {
      int res;
      cin >> res;
      victims[res - 1] = true;
    }
  }
  int ans = 0;
  for(int i = 0;i < a;i++)
  {
    if(!victims[i])
    {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}