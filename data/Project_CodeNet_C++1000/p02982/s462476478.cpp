#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, d;
  cin >> n >> d;
  wi x(n, vi(d));
  rep(i, n)rep(j, d)cin >> x[i][j];

  int cnt=0;
  rep(i, n){
    for(int j=i+1; j<n; j++){
      int sum=0;
      rep(k, d){
        sum+=(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
      }
      rep(k, 126)if((k+1)*(k+1)==sum)cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}