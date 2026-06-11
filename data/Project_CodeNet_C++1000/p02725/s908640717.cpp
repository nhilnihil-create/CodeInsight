#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;



int main() {
  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  vector<int> sect(n);
  for(int i=1; i<n; i++){
    sect[i] = a[i] - a[i-1];
  }
  sect[0] = a[0]+k-a[n-1];
  
  sort(sect.rbegin(), sect.rend());
  cout << k-sect[0] << endl;
  
  return 0;
}
