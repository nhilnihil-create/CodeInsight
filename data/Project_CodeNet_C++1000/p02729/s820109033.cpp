#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;

int main() {
  int n, m;
  cin >> n >> m;
  cout << n*(n-1)/2 + m*(m-1)/2 << endl;
  return 0;
}