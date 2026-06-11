#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFF 9223372036854775807
#define ll long long
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,m,n) for(int i=m;i<n;i++)
#define ALL(N) (N.begin(),N.end())

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int M, D, ans=0;
  cin >> M >> D;
  if(M<4 || D<22) ans=0;
  else {
    for(int m=4; m<=M; m++) {
      for(int d=22; d<=D; d++) {
        int d_1=d%10, d_10=d/10;
        if(d_1>=2 && d_1*d_10==m) ans++;
      }
    }
  }
  cout << ans << endl;
}