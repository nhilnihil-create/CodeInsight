
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<numeric>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main () {
  int n,sum = 100000000;
  cin >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  for (int i = 0; i < n-1; i++){
    int sum1 = 0,sum2 = 0;
    for (int j = 0; j <= i; j++){
      sum1 += w[j];
    }
    for (int j = i+1; j < n; j++){
      sum2 += w[j];
    }
    if (abs(sum1 - sum2) < sum){
      sum = abs(sum1 - sum2);
    }  
  }
  cout << sum << '\n';
  return 0;
}