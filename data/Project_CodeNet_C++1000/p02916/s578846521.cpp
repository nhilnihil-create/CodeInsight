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
  int n,sum = 0,m;
  cin >> n;
  vector<int> a(n),b(n),c(n-1);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  for (int i = 0; i < n-1; i++){
    cin >> c[i];
  }
  for (int i = 0; i < n; i++){
    sum += b[a[i]-1];
    if (i + 1 != 1 && a[i] - 1 == m){
      sum += c[a[i-1]-1];
    }
    m = a[i];
  }
  cout << sum << '\n';
  return 0;
}