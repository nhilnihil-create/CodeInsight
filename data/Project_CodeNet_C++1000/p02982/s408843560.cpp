#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int N, D; cin >> N >> D;
  int X[N][D];
  rep(i,N) rep(j,D) cin >> X[i][j];
  
  int cnt = 0;
  for (int i=0;i<N;i++){
    for (int j=i+1;j<N;j++){
      int se = 0;
      rep(d,D) se += (X[i][d]-X[j][d])*(X[i][d]-X[j][d]);
      int dst = sqrt(se);
      if (dst*dst == se) cnt++;
    }
  }

  cout << cnt << endl;

  // cout << fixed << setprecision(6);
  return 0;
}
