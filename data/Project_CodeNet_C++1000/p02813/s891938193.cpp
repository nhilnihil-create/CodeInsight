#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  vector <int> P(N), Q(N);
  rep(i,N) cin >> P[i];
  rep(i,N) cin >> Q[i];
  vector <int> a(N);
  rep(i,N) a[i] = i + 1;
  map <vector<int>, int> mp;
  do {
    mp[a] = mp.size();  //0-indexedで順番を格納
  } while (next_permutation(a.begin(), a.end()));

  int ans = abs(mp[P] - mp[Q]);
  cout << ans << endl;
  return 0;
}
