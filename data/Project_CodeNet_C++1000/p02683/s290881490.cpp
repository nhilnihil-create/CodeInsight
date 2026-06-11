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

const int max_n = 15, INF = 1e8;
int n, m, x, ans = INF;
int c[max_n], a[max_n][max_n];
bool poss = false;

int main(){
    cin >> n >> m >> x;
    rep(i, n){
        cin >> c[i];
        rep(j, m){
            cin >> a[i][j];
        }
    }

    for(int bit = 0; bit < (1 << n); bit++){
        int sum = 0;
        int pts[m] = {0};
        for(int i = 0; i < n; i++){
            if((bit >> i) & 1) {
                sum += c[i];
                for(int j = 0; j < m; j++) pts[j] += a[i][j];
            }
        }
        auto iter = min_element(pts, pts+m);
        if(*iter >= x && ans > sum) poss = true, ans = sum;
    }
    if(poss) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}