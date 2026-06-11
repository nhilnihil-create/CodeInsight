#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  ll a,v,b,w,t;
  cin >> a >> v >> b >> w >> t;
  if(v * t >= w * t + abs(a - b))cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
