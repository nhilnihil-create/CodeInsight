// Editorial
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  long long k;
  cin >> k;
  vector<int> a(n);
  vector<int> f(n);
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<n;i++) cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());
  long long start = 0;
  long long end = pow(10, 12);
  while(start != end) {
    long long h = (start + end) / 2;
    long long tmp = 0;
    for(int i=0;i<n;i++) {
      long long t = h / f[i];
      tmp += max(0LL, a[i] - t);
    }
    if(tmp <= k) end = h;
    else start = h + 1;
  }
  cout << start << endl;
}
