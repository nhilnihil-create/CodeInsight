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
  vector<int>H(n);
  rep(i,n) cin >> H[i];
  for (int i=n-1; i>=1; i--){
    if (H[i] >= H[i-1]) continue;
    else{
      H[i-1]--;
      if (H[i] < H[i-1]){
        //cout << i << "," << i-1 << endl;
        //cout << H[i] << endl;
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}