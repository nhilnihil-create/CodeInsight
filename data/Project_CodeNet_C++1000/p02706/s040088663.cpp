#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{

  int n,m;
  int x;
  cin >> n >> m;
  rep(i,m){
    cin >> x;
    if(n - x < 0) {
      cout << -1 << endl;
      return 0;
    }
    n -= x;
  }
  cout << n << endl;
  return 0;
}