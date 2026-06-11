#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG


signed main() {
  int N; cin >> N;
  vector<int> L(N);
  rep(i, N) cin >> L[i];
  
  sort(all(L));
  
  int ans = 0;
  rep(i, N) for(int j=i+1; j<N; j++) {

    ans += max((int)(0), (int)(distance(upper_bound(L.begin()+j+1, L.end(), L[j]-L[i]), lower_bound(L.begin()+j+1, L.end(), L[j]+L[i]))));
    //cout << L[i] << " " << L[j] << " " << ans << endl;
  }
  
  cout << ans << endl;
}
