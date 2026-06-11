#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e11;
using Graph = vector<vector<int>>;

signed main(){
  int N;
  cin >> N;

  int cnt = 0;
  for( int i = 0; i < N; i++ ){
    int A, B;
    cin >> A >> B;
    if( A == B ) cnt++;
    else cnt = 0;
    if( cnt == 3 ){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
