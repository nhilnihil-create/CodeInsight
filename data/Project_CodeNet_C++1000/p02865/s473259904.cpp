#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  cout << n / 2 - (n % 2 == 0) << endl;
  return 0;
}
