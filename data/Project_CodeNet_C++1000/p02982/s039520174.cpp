#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,d; cin >> n >> d;
  vector<vector<int>> x(n,vector<int>(d));
  rep(i,n){
    rep(j,d) cin >> x[i][j];
  }

  int cnt=0;
  rep(i,n){
    rep(j,n){
      int r2 = 0;
      rep(k,d) r2 += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      
      for(int s = 1;s<=10000;s++){
	if(s*s==r2) cnt++;
      }
    }
  }  
  cnt /= 2;
  
  cout << cnt << endl;
  
  return 0;
}
