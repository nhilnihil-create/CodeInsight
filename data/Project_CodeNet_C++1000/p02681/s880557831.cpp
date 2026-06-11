#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using p = pair<int, int>;

int main() {
  string S, T;
  cin >> S >> T;
  int flag = 0;
  rep(i,(int)S.size()){
  if (S[i] != T[i]) {flag=1;break;};
  };
  if ((flag==0) && ((int)S.size() + 1 == (int)T.size()))cout << "Yes"<< endl;
  else cout << "No"<< endl;
}