#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int ans = min({a+b, b+c, c+a});
  cout << ans << endl;

}
