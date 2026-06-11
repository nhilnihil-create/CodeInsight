#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k; cin >> n >> k;
  vector<long long int> h(n);
  for(int i = 0; i < n; ++i) cin >> h[i];
  
  if(k >= n) cout << 0;
  else
  {
    sort(h.begin(), h.end());
    int rem = n - k;
    cout << accumulate(h.begin(), h.begin()+rem, 0LL);
  }
  return 0;
}
