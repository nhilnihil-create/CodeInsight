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

string s;
int sum = 0;

int main(){
    getline(cin, s);

    int m=1, i=0;
    while(i++ < s.length()-1){
        if(i % 2 != 0){
            sum += m*9;
        }
        m *= 10;
    }

    int n = stoi(s);
    if(s.length() % 2 != 0) sum += n-m +1;
    cout << sum << endl;
    return 0;
}