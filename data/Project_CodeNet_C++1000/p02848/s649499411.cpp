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
string s;

int main(){
    cin >> n >> s;

    rep(i, s.length()){
        int tmp = n;
        if(s[i] + n > 'Z'){
            tmp = n - ('Z' - s[i] + 1);
            s[i] = 'A' + tmp;
        }else{
            s[i] += tmp;
        }
    }
    cout << s << endl;
}