#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n; cin >> n;
  int ans = 0;
  if(n < 3){cout << "0" << endl; return 0;}
  vector<ll> data(n); REP(i,n) cin >> data[i];
  sort(ALL(data));
  REP(i,n-2){FOR(j,i+1,n-1){FOR(k,j+1,n){
    if(data[i] == data[j] || data[j] == data[k] || data[k] == data[i])
      continue;
    if(data[i] + data[j] > data[k] && data[j] + data[k] > data[i] && data[k] + data[i] > data[j] )
      ans++;
  }}}
  cout << ans << endl;
}