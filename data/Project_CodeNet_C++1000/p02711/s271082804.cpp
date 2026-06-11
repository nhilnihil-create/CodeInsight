#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T &a, T b) {if (a < b) {a = b;return 1;}return 0;}
template<class T> inline bool chmin(T &a, T b) {if (a > b) {a = b;return 1;}return 0;}

int main(){
  char a,b,c;
  cin >> a >> b >> c;
  if (a == '7' || b == '7' || c == '7') cout << "Yes" << endl;
  else cout << "No" << endl;
}
