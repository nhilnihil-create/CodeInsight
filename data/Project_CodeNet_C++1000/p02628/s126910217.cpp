#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int n,k,s=0; cin >> n >> k;
  vector<int> p(n);
  for(int i=0; i<n; ++i) cin >> p[i];
  sort(p.begin(), p.end());

  for(int i=0; i<k; ++i) s+=p[i];
  cout << s;
}