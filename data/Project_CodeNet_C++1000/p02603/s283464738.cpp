#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e14;
using Graph = vector<vector<int>>;

signed main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> A[i];

  int money = 1000;
  int kabu = 0;
  for( int i = 0; i < N; i++ ){
    if( i > 0 && A[i] > A[i-1] ){
      money += kabu*A[i];
      kabu = 0;
    }
    if( i < N-1 && A[i] < A[i+1] ){
      kabu += (money/A[i]);
      money -= (money/A[i])*A[i];
    }
  }
  money += kabu*A[N-1];
  cout << money << endl;

}
