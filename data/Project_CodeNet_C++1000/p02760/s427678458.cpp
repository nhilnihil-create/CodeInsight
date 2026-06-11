#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  vector<vector<int>> a(3,vector<int>(3));
  vector<vector<int>> cnt(3,vector<int>(3));
  rep(i,3)rep(j,3)cin >> cnt[i][j];
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i,n){
    cin >> b[i];
    rep(j,3){
      rep(k,3){
        if(b[i]==cnt[j][k])a[j][k]++;
      }
    }
  }
  bool ans = false;
  rep(i,3){
    if(a[i][0]>0&&a[i][1]>0&&a[i][2]>0)ans=true;
    if(a[0][i]>0&&a[1][i]>0&&a[2][i]>0)ans=true;
  }
  if(a[0][0]>0&&a[1][1]>0&&a[2][2]>0)ans=true;
  if(a[0][2]>0&&a[1][1]>0&&a[2][0]>0)ans=true;

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
