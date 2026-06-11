#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
  
int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i,n){
    cin >> vec.at(i);
  }
  int sum1, sum2;
  sum1 = 0;
  sum2 = 0;
  rep(i,n){
    sum1 += vec.at(i);
  }
  rep(i,n){
    sum2 += vec.at(i) * vec.at(i);
  }
  cout << (sum1 * sum1 - sum2) / 2;
  return 0;
}