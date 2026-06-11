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
  unsigned long long H,W;
  cin >> H >> W;

  if(H%2 == 1 && W%2 == 1 && H != 1 && W != 1){
    cout << (H * W + 1) / 2 << endl;
  }else if(H ==1 || W == 1){
    cout << 1 << endl;
  }else{
    cout << (H * W) / 2 << endl;
  }
}