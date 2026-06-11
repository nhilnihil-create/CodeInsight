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

const int max_n = 20;
int n, ans = 0;;
int a[max_n], x[max_n][max_n], y[max_n][max_n];

int main(){
    cin >> n;
    rep(i, n){
        cin >> a[i];
        rep(j, a[i]){
            cin >> x[i][j] >> y[i][j];
        }
    }
    for(int bit = 0; bit < (1 << n); bit++){
        bool flag = true;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if((bit >> i) & 1) {
                rep(j, a[i]) {
                    if((bit >> (x[i][j]-1) & 1) != y[i][j]){
                        flag = false;
                        break;
                    }
                }
                sum++;
            }
            if(!flag) break;
        }
        if(ans < sum && flag) ans = sum;
    }
    cout << ans << endl;
    return 0;
}