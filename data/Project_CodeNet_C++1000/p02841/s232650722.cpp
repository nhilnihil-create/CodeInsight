#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int m[2], d[2];
  cin >> m[0] >> d[0] >> m[1] >> d[1];
  if(d[0] - d[1] < 0)
    cout << 0 << endl;
  else
    cout << 1 << endl;
  return 0;
}