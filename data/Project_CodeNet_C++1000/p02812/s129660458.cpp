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

const int max_n = 55;
int n;
string s, txt = "ABC";

int main(){
    cin >> n;
    cin.ignore();
    getline(cin, s);
    int cnt = 0;
    rep(i, n-2) {
        if(s.substr(i, 3) == txt){
            cnt++;
            i+=2;
        }
    }
    cout << cnt << endl;
    return 0;
}