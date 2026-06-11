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

long long ans = 0;
int n;
string s;
vector<int> pos[10];
int main(){
    cin >> n;
    cin >> s;

    rep(i, n) pos[s[i]-'0'].push_back(i);

    rep(i, 1000){
        int h = i/100;
        int t = i/10;
        t %= 10;
        int o = i % 10;
        if(pos[h].size() == 0 || pos[t].size() == 0 || pos[o].size() == 0) continue;

        int p_h = pos[h][0];
        int p_t=0, p_o;
        rep(j, pos[t].size()){
            if(pos[t][j] > p_h){
                p_t = pos[t][j];
                break;
            }
        }
        if(p_t == 0) continue;

        rep(j, pos[o].size()){
            if(pos[o][j] > p_t){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}