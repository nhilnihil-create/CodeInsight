#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
  vector<vector<int>> a(3, vector<int>(3));
  rep(i,3){
    rep(j,3){
      cin >> a[i][j];
    }
  }
  int n;
  int counts =0;
  cin >> n;
  rep(i,n){
    int b;
    cin >> b;
      rep(i,3){
        rep(j,3){
          if(a[i][j]==b) a[i][j] = 200;
        }
      }
  }
  rep(i,3){
    rep(j,3){
      if(a[i][j] == 200) counts++;
    }
  }
  int ans = 0;
  if(counts < 3) cout << "No" << endl;
  else {
    rep(i,3){
    if(a[i][0] ==200 && a[i][1] ==200 && a[i][2] ==200 ) ans++;
  }
      rep(i,3){
    if(a[0][i] ==200 && a[1][i] ==200 && a[2][i]==200) ans++;
  }
    if(a[0][0] ==200 && a[1][1] ==200 && a[2][2]==200) ans++;
    if(a[0][2] ==200 && a[1][1] ==200 && a[2][0]==200) ans++;


  if(ans != 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  }
}
