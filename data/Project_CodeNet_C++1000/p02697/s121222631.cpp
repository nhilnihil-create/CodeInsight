#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e18;
using Graph = vector<vector<int>>;

signed main()
{
  int N, M;
  cin >> N >> M;

  if (M % 2 == 1){
    int sa = M - 1;
    for (int i = 1; sa > 1; i++){
      cout << i << " " << i + sa << endl;
      sa -= 2;
    }
    sa = M;
    for (int i = M + 1; sa > 0; i++){
      cout << i << " " << i + sa << endl;
      sa -= 2;
    }
  }else{
    int sa = M;
    for (int i = 1; sa > 1; i++){
      cout << i << " " << i + sa << endl;
      sa -= 2;
    }
    sa = M-1;
    for( int i = M+2; sa > 0; i++ ){
      cout << i << " " << i+sa << endl;
      sa -= 2;
    }
  }
}
