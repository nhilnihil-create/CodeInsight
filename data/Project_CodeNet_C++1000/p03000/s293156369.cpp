
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
  int n,x,sum = 0,cnt = 1;
  cin >> n >> x;
  vector<int> l(n);
  for (int i = 0; i < n; i++){
    cin >> l[i];
    sum += l[i];
    if (sum <= x){
      cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}