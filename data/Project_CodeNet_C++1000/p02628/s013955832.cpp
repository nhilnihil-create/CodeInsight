#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>

#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  
  int n, k, count = 0;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  Vsort(p);
  rep(i, k) count += p[i];
  cout << count;

  return 0;
}
