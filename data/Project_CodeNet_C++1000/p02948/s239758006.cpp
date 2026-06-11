#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

int main(){
  int n, m;
  cin >> n >> m;
  P p[100000];
  rep(i, n){
    int a, b;
    cin >> a >> b;
    p[i] = P(b, a);
  }
  sort(p, p + n);
  reverse(p, p + n);
  vector<int> vec(n);
  rep(i, m) vec.push_back(i+1);
  int ans = 0;
  for(int i = 0; i < n; i++){
    int a = p[i].second, b = p[i].first;
    auto it = lower_bound(all(vec), a);
    if(it == vec.end()) continue;
    vec.erase(it);
    ans += b;
      
  }
  cout << ans << endl;
}