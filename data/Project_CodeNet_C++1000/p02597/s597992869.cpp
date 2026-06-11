#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int all = 0, cnt = 0;
  rep(i,n){
    if (s.at(i) == 'R') all++;
  }
  rep(i,all){
    if (s.at(i) == 'R') cnt++;
  }
  int ans = all - cnt;
  cout << ans << endl;
  return 0;
}
