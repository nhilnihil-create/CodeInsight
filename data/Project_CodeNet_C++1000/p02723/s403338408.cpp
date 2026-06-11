#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}


int main(){
  string s;
  cin >> s;
  if (s.at(2) == s.at(3) && s.at(4) == s.at(5)) cout << "Yes" << endl;
  else cout << "No" << endl;
}
