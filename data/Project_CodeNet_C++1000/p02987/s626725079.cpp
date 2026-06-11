#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  string s;
  cin >> s;
  rep(i,4){
    int cnt = 0;
    rep(j,4){
      if(s[i] == s[j]) cnt ++;
    }
    if(cnt !=2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
