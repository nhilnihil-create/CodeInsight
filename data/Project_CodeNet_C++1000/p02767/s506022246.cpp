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
  int L=100,R=0;
  int ans = INF;
  int sum;
  vector<int> tmp(n);
  REP(i,n){
    cin >> tmp[i];
    L = min(tmp[i],L);
    R = max(tmp[i],R);
  }
  for(int i = L; i <= R;i++){
    sum = 0;
    REP(j,n){
      sum += (tmp[j] - i)*(tmp[j] - i);
    }
    ans = min(ans,sum);
  }
  cout << ans << endl;
}