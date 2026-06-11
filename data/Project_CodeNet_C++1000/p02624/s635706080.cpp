#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int main(){

  int n;
  cin >> n;
  vector<int> d(n+1,0);
  for(int i = 1; i < n+1; i++){
    for(int j = i; j < n+1; j += i){
      d[j]++;
    }
  }

  
  ll ans = 0;
  for(int k = 1; k < n+1; k++){
    ans += ll(k)*d[k];
  }
  cout << ans << endl;
}
