#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cntAC(n+1), cntWA(n+1);
  int ans = 0, penalty = 0;
  rep(i, m){
    int p;
    string s;
    cin >> p >> s;
    if(s == "WA" && cntAC[p] == 0){
      cntWA[p]++;
    }else if(s == "AC" && cntAC[p] == 0){
      ans++;
      cntAC[p] = 1;
    }
  }
  for(int i = 1; i <= n; i++){
    if(cntAC[i] == 1){
      penalty += cntWA[i];
    }
  }

  cout << ans << " " << penalty << endl;


}



