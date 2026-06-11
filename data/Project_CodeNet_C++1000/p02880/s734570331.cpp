#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int) (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int) (n); i++)
#define _GLIBCXX_DEBUG

template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int n;

int main(){
    cin >> n;
    bool poss = false;
    rep2(i, 1, 10) rep2(j, 1, 10){
      if(i*j == n) poss = true;
    }
    if(poss) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}