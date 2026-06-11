#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
void dfs(int depth,ll x,vector<ll> &num){
  num.push_back(x);
  if(depth == 11) return;
  ll tmp = x % 10;
  for(int i = -1; i < 2; i++){
    if(tmp + i >= 0 && tmp + i < 10) dfs(depth + 1, x * 10 + tmp + i, num); 
  }
}
int main()
{
  int K; cin >> K;
  vector<ll> num;
  FOR(i,1,10)
    dfs(1,i,num);
  sort(ALL(num));
  cout << num.at(K - 1) << endl;
}