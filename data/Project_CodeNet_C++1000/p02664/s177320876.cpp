#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main() {
  string S;
  cin >> S;
  for( int i = 0; i < S.size(); i++ ){
    if( S.at(i) == '?' ) S.at(i) = 'D';
  }
  cout << S << endl;
}