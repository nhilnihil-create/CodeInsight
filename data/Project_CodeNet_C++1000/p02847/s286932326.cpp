#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  string S[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  reverse(S, S+7);
  // mapでどの曜日が日曜日から何日後かを管理
  map <string, int> X;
  rep(i, 7) X[S[i]] = i + 1;

  string s;
  cin >> s;
  cout << X[s] << endl;
}
