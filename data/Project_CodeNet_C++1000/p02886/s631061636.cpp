#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  int sum = 0,n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    cin >> d[i];
  }
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      sum += d[i] * d[j];
    }
  }
  cout << sum << '\n';
  return 0;
}