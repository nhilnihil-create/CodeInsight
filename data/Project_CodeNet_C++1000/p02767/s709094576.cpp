#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,f,n) for(int i=f; i<(n); i++)
int m_x[4] = { 0, 0,-1, 1};
int m_y[4] = {-1, 1, 0, 0};

int main()
{
  int n,ans = 2147483646;
  cin >> n;
  int x[n];
  REP(i,0,n){
    cin >> x[i];
  }
  REP(j,0,100){
    int g = 0;
    REP(i,0,n){
      g += (x[i] - j)*(x[i] - j);
    }
    ans = min(g,ans);
  }
  cout << ans << endl;
  
  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}