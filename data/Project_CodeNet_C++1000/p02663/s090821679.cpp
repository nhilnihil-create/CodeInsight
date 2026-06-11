#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main(){
  int A, B, C, D, K;
  cin >> A >> B >> C >> D >> K;
  
  int oki = (C-A)*60 - B + D;
  cout << max(0LL, oki-K) << endl;
  
}