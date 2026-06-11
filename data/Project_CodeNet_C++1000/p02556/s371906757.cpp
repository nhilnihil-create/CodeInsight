#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> xpy(n),xmy(n);
  for (int i = 0; i < n; i++)
  {
    long long x,y;
    cin >> x >> y;

    xpy[i] = x+y;
    xmy[i] = x-y;
  }
  sort(xpy.begin(),xpy.end());
  sort(xmy.begin(),xmy.end());

  long long ans = max(abs(xpy[0]-xpy[n-1]), abs(xmy[0]-xmy[n-1]));
  cout << ans << endl;
}