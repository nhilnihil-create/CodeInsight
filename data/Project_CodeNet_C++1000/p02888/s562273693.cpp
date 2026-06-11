#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
  int n; cin >> n;
  vector<int>L(n+1); rep(i,n) cin >> L[i];
  L[n] = INF;
  sort(L.begin(), L.end());
  int ans = 0;
  for (int i=0; i<=n-2; i++){
    for (int j=i+1; j<=n-1; j++){
      int Li_plus_Lj = L[i] + L[j];
      auto k_itr = lower_bound(L.begin(), L.end(), Li_plus_Lj);
      if (k_itr != L.end()){
        int k_index = k_itr - L.begin();
        ans += k_index-1-j;
      }
    }
  }
  cout << ans << endl;
}