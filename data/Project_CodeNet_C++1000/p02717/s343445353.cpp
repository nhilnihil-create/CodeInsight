#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int x, y, z;
  cin >> x >> y >> z;

  swap(x, y);
  swap(x, z);

  cout << x << " " << y << " " << z << endl;
}
