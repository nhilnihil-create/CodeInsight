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
  ll H, W, ans;
  cin >> H >> W;
  
  if(H == 1 || W == 1){
    ans = 1;
  }
  else{
    ans = (H * W + 1) / 2; 
  }
  cout <<  ans << endl;
} 