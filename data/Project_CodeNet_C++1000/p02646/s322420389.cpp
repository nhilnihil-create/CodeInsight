#include <bits/stdc++.h>
using namespace std;
int64_t A, B, V, W, T;

void solve()
{
  int64_t t = (abs(A - B) + (V - W - 1)) / (V - W);
  if (t <= T)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main()
{
  cin >> A >> V >> B >> W >> T;
  if (A == B)
    cout << "YES" << endl;
  else if (W >= V)
    cout << "NO" << endl;
  else
    solve();
}