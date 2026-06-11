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

typedef long long ll;
const int max_n = 5010;
const ll INF = 1e15;
ll n, ans = -INF;
int k;
int p[max_n];
ll c[max_n];

int main(){
    cin >> n >> k;
    rep(i, n) cin >> p[i], p[i]--;
    rep(i, n) cin >> c[i];

    rep(i, n){
        vector<int> v;
        int now = i;
        while(true){
            now = p[now];
            v.push_back(c[now]);
            if(now == i) break;
        }
        int sz = v.size();
        ll sum = accumulate(v.begin(), v.end(), 0LL);
        ll cur = 0;
        rep(j, min(sz, k)){
            cur += v[j];
            ans = max(ans, cur + (k-j-1) / sz * max(sum, 0LL));
        }
    }
    cout << ans << endl;
}