#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll x[55];
ll y[55];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];


  int ans = n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      ll X = x[i] - x[j];
      ll Y = y[i] - y[j];
      int t = 0;
      for(int k = 0; k < n; k++) {
	for(int l = 0; l < n; l++) {
	  if(k == l) continue;
	  ll K = x[k] - x[l];
	  ll L = y[k] - y[l];
	  if(K == X && Y == L) t++;
	}
      }
      ans = min(ans,n - t);
    }
  }

  cout << ans << endl;
}
