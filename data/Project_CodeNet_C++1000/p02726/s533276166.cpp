#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> ans(N);
  for (int i = 1; i <= N; i++)
  {
    for (int j = i + 1; j <= N; j++)
    {
      ans[min(abs(X - i) + 1 + abs(j - Y), j - i)]++;
    }  
  }
  
  for (int i = 1; i < N; i++)
  {
    cout << ans[i] << endl;
  }
  
  return 0;
}
