
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

int main() {
  int n,sum = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 1; i < n-1; i++){
    if ((a[i] < a[i-1] && a[i] > a[i+1]) || (a[i] > a[i-1] && a[i] < a[i+1]) /*つまり、つまりよ。ってことは、「二番目か否か」っていうことじゃねぇ～の？（笑笑）*/){
      sum++;
    }
  }
  cout << sum << '\n';
  return 0;
}