#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1000000000; // 10^9

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;

  double ans;
  for(int i=1; i<=n; i++) {
    ans = i*1.08;
    if(floor(ans) == n) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << ":(" << '\n';
  return 0;
}

