#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////


int main() {
  long long a, v;
  long long b, w;
  long long t;
  cin >> a >> v;
  cin >> b >> w;
  cin >> t;
  int d = abs(a-b);
  if (v <= w) {
    cout << "NO" << endl;
    return 0;
  }
  if ((v - w)*t >= d) {
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }

  return 0;
}

// EOF