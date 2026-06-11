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

const int max_h = 6, max_w = 6;
int h, w, k, ans = 0;
char c[max_h][max_w];

int main(){
    cin >> h >> w >> k;
    string s;
    cin.ignore();
    rep(i, h) {
        getline(cin, s);
        rep(j, w) c[i][j] = s[j];
    }

    for(int bita = 0; bita < (1 << h); bita++){
        for(int bitb = 0; bitb < (1 << w); bitb++){
            int cnt = 0;
            rep(i, h) rep(j, w){
                if(((bita >> i) & 1) && ((bitb >> j) & 1)){
                    if(c[i][j] == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}