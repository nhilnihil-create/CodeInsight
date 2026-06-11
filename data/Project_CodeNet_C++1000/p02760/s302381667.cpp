#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  wi a(3, vi(3));
  rep(i, 3)rep(j, 3)cin >> a[i][j];
  int n;
  cin >> n;
  wi cnt(3, vi(3));
  rep(i, n){
    int b;
    cin >> b;
    rep(i, 3)rep(j, 3){
      if(a[i][j]==b){
        cnt[i][j]++;
        i=3;j=3;
      }
    }
  }

  string ans="No";
  rep(i, 3){
    if(cnt[i][0]==1&&cnt[i][1]==1&&cnt[i][2]==1)ans="Yes";
    if(cnt[0][i]==1&&cnt[1][i]==1&&cnt[2][i]==1)ans="Yes";
  }
  if(cnt[0][0]==1&&cnt[1][1]==1&&cnt[2][2]==1)ans="Yes";
  if(cnt[2][0]==1&&cnt[1][1]==1&&cnt[0][2]==1)ans="Yes";

  cout << ans << endl;

  return 0;
}