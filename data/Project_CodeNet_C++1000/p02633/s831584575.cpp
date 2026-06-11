#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e14;
using Graph = vector<vector<int>>;

signed main(){
  int X;
  cin >> X;
  int a = 1;
  while( true ){
    if( (X*a)%360 == 0 ){
      cout << a << endl;
      return 0;
    }
    a++;
  }


}
