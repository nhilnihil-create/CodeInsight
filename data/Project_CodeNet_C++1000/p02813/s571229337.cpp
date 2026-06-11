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

const int max_n = 10;
int n, a, b;
int p[max_n], q[max_n];
vector<int> v;

int main(){
    cin >> n;
    rep(i, n) cin >> p[i], v.push_back(i+1);
    rep(i, n) cin >> q[i];

    int cnt = 1;
    do{
        rep(i, n){
            if(v[i] != p[i]) break;
            if(i >= n-1) a = cnt;
        }
        rep(i, n){
            if(v[i] != q[i]) break;
            if(i >= n-1) b = cnt;
        }
        cnt++;
    }while(next_permutation(v.begin(), v.end()));

    cout << abs(a-b) << endl;
    return 0;
}