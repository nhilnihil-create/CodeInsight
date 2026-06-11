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
  int n,sum = 0,m = 1000,c;
  cin >> n;
  vector<int> a(n);
  cin >> a[0];
  for (int i = 1; i < n; i++){
    a[i] = a[i-1] + 1;
  }
  for (int i = 0; i < n; i++){
    if (m > abs(0 - a[i])){
      m = abs(0 - a[i]);
      c = i;
    } 
  }
  for (int i = 0; i < n; i++){
    if (i != c){
      sum += a[i];
    }
  }
  cout << sum << '\n';
  return 0;
}