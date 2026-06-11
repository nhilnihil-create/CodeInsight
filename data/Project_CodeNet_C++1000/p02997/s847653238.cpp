#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;

int main()
{
  int n,k; cin>>n>>k;

  int t = (n-2)*(n-1)/2;
  if (t < k) {
    cout << -1 << endl;
    return 0;
  }

  printf("%d\n", n-1+(t-k));
  for (int i=2; i<=n; i++) {
    printf("%d %d\n", 1, i);
  }
  for (int i=2; i<n; i++) {
    for (int j=i+1; j<=n; j++) {
      if (t <= k) return 0;
      printf("%d %d\n", i, j);
      t--;
    }
  }

  return 0;
}
