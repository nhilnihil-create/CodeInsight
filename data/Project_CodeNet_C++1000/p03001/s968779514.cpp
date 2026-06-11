#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll w, h, x, y;
  cin >> w >> h >> x >> y;
  printf("%.9f", w*h/2.0);
  cout << " ";
  if (w/2.0 == x && h/2.0 == y) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}