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
  int N; cin >> N;
  int x[N], y[N]; rep(i,N) cin >> x[i] >> y[i];
  map<pair<ll,ll>,int> d;

  for (int i=0;i<N-1;i++){
    for (int j=i+1;j<N;j++){
      ll dx = x[i]-x[j], dy = y[i]-y[j];
      if (dx<0) dx = -dx, dy = -dy;
      if (dx==0) dy = abs(dy);
      d[make_pair(dx,dy)]++;
    }
  }
  int MAX = 0;
  for (auto p:d){
    MAX = max(MAX, p.second);
  }
  cout << N - MAX << endl;
  

  // cout << fixed << setprecision(10);
  
  return 0;
}
