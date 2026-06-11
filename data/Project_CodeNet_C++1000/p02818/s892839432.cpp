#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)




int main() {
  
  ll A, B, K;
  cin >> A >> B >> K;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));
  if (K <= A) cout << A - K << " " << B << endl;
  else if(K <= (A+B))  cout << 0 << " " << (A+B) - K << endl;
  else cout << 0 << " " << 0 << endl;
  

  return 0;
}
