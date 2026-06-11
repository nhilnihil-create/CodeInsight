#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n,m;
  cin >> n >> m;
  vector<bool> ok(n+1, false);
  vector<int> pena(n+1);
  int ans=0;
  rep(i,m){
    int p;
    string s;
    cin >> p >> s;
    if(s == "AC" && !ok[p]){
      ans ++;
      ok[p] = true;
    }
    if(s == "WA" && !ok[p]) pena[p]++;
  }
  int sum = 0;
  for(int i=1; i<=n; i++){
    if(ok[i]) sum += pena[i];
  }
  cout << ans << " " << sum << endl;
}
