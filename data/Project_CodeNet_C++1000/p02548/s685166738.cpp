#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  REP(i,1,n + 1){
    ans += (n - 1) / i;
  }
  cout << ans << endl;
  return 0;
}
