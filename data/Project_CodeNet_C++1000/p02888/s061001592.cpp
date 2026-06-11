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
  vi l(n);
  rep(i,n) cin >> l.at(i);
  sort(l.begin(), l.end());
  int ans = 0;
  REP(i,0,n-2)REP(j,i+1,n-1)REP(k,j+1,n){
    if (l.at(i) + l.at(j) <= l.at(k)){
      break;
    }
    ans++;
    //printf("%d %d %d\n", l.at(i), l.at(j), l.at(k));
  }
  cout << ans << endl;
  return 0;
}
