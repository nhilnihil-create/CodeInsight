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
  vector<int> L(n+1);
  rep(i,n) cin >> L[i];
  L[n] = INF;
  sort(L.begin(), L.end());
  int ans = 0;
  for (int i=0; i<n-2; i++){
    for (int j=i+1; j<n-1; j++){
      for (int k=j+1; k<n; k++){
        if (L[k] < L[i] + L[j]) ans++;
      }
    }
  }
  cout << ans << endl;
}