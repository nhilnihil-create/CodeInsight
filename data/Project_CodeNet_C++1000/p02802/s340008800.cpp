#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> cntAC(n,0), cntWA(n,0);
  int p;
  string s;
  rep(i,m){
    cin >> p >> s;
    p--;
    if(cntAC[p]==1)continue;
    if(s=="AC")cntAC[p]++;
    else cntWA[p]++;
  }
  int totalAC=0, totalWA=0;
  rep(i,n){
    totalAC += cntAC[i];
    if(cntAC[i]==1){
      totalWA += cntWA[i];
    }
  }
  cout << totalAC << ' ' << totalWA << endl;
  return 0;
}
