#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  int n; cin >> n;
  vector<long long> l(n);
  for(int i=0; i<n; i++) cin >> l[i];
  sort(all(l));
  int cnt = 0;
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      for(int k=j+1; k<n; k++) {
        if (l[i] == l[j] || l[j] == l[k] || l[k] == l[i]) continue;
        if (l[i] + l[j] > l[k] && l[j] + l[k] > l[i] && l[k] + l[i] > l[j]) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;


  return 0;
}

// EOF