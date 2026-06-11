#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int h, w, a, b; cin >> h >> w >> a >> b;
  a--; b--;
  vector<vector<int>> s(h, vector<int>(w, 0));
  rep(i, h){
    rep(j, w){
      if(i <= b && j <= a) s[i][j] = 1;
      if(i > b && j > a) s[i][j] = 1;
    }
  }

  rep(i, h){
    rep(j, w) cout << s[i][j];
    cout << endl;
  }


  return 0;
}
