#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  static int rewards[] = {300000, 200000, 100000};
  int x, y, r = 0;
  cin >> x >> y;
  if (x <= 3) r += rewards[x - 1];
  if (y <= 3) r += rewards[y - 1];
  if (x == 1 && y == 1) r += 400000;
  cout << r << endl;
  return 0;
}