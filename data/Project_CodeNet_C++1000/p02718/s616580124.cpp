#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int n,m,sum = 0;
  cin >> n >> m;
  int a[n];
  rep(i,n) {
    cin >> a[i];
    sum+=a[i];
  }
  sort(a,a + n);
  reverse(a,a + n);
  cout << ((double)a[m - 1] >= (double)sum / (4*m) ? "Yes" : "No") << endl;
  return 0;
}