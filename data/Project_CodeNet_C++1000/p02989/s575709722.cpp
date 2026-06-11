#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int N; cin >> N;
  vector<int> d(N);
  rep(i,N)cin >> d[i];
  sort(d.begin(),d.end());
  int arc = d.size()/2; 
  int abc = d.size()/2 -1;
  int ans = d[arc] - d[abc];
  cout << ans << endl;
  


	return 0;
}

