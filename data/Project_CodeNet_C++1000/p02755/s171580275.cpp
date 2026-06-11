#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  double a, b;
  cin >> a >> b;
  int ans = -1;
  rep(i, 100000){
    
    if((int)(i * 0.08) == a && b == (int)(i * 0.1)){
      ans = i;
      break;
    }
  }
  cout << ans << endl;


  return 0;
}