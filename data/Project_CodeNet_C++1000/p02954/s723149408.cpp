#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  string s;
  cin >> s;
  n = s.size();
  vi ans(n);
  rep(i,2){
    int cnt = 0;
    rep(j,n){
      if (s.at(j) == 'R') cnt++;
      else {
        ans.at(j) += cnt / 2;
        ans.at(j-1) += (cnt + 1) / 2;
        cnt = 0;
      }
    }
    reverse(ans.begin(), ans.end());
    reverse(s.begin(), s.end());
    rep(j,n){
      if (s.at(j) == 'L') s.at(j) = 'R';
      else s.at(j) = 'L';
    }
  }
  rep(i,n) printf("%d ", ans.at(i));
  printf("\n");
  return 0;
}
