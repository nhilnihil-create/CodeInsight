#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end();
int main() {
  int a;
  string b;
  cin >> a >> b;
  for(int i=0;i<b.size();i++){
    b.at(i) += a;
    while(b.at(i)>'Z')b.at(i) -=26;
  }
  cout << b;
}