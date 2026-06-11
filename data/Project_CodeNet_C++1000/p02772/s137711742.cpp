#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) cin >> vec[i];
  rep(i, n) {
    if (vec[i] % 2 == 0) {
      if (vec[i] % 3 == 0 || vec[i] % 5 == 0) continue;

      cout << "DENIED" << endl; 
      return 0;
    }
  }
  cout << "APPROVED" << endl; 
  return 0;
}