#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int a, b, m; cin >> a >> b >> m;
  vector<int> aa(a);
  vector<int> bb(b);
  vector<int> x(m);
  vector<int> y(m);
  vector<int> c(m);
  for(int i=0; i<a; i++) cin >> aa[i];
  for(int i=0; i<b; i++) cin >> bb[i];
  int ans = *min_element(all(aa)) + *min_element(all(bb));
  for(int i=0; i<m; i++) {
    cin >> x[i] >> y[i] >> c[i];
    ans = min(ans, aa[x[i]-1] + bb[y[i]-1] - c[i]);
  }
  cout << ans << endl;
  
}

// EOF