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

const int max_n = 1010;
int n;
int a[max_n];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];

    bool succ = true;
    rep(i, n){
        if(a[i] % 2 == 0){
            if(a[i] % 3 != 0 && a[i] % 5 != 0) succ = false;
        }
    }
    if(succ) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;
}