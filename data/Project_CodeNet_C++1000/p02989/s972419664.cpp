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

  if (n % 2 == 1){
    cout << 0 << endl;
    return 0;
  }

  vi d(n);
  rep(i,n) cin >> d.at(i);
  sort(d.begin(), d.end());
  int ans = d.at(n/2) - d.at(n/2-1);
  cout << ans << endl;
  return 0;
}
