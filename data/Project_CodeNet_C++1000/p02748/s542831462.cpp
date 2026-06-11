#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int INF = 100100101;

int func(int choco, int d){
  int ret=1;
  for(int i = 1; i < d; i++){
	if(i * choco + 1 <= d){
      ret++;
    }
  }
  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int r,m,d;
  cin>>r>>m>>d;
  int R[r], M[m];
  int min_r = INF;
  for(int i=1;i<=r;i++) {
    cin >> R[i];
	min_r = min(min_r, R[i]);
  }
  int min_m = INF;
  for(int i = 1;i<=m;i++) {
    cin >> M[i];
    min_m = min(min_m, M[i]);
  }
  int x, y, c;
  int discountedSum = min_r + min_m;
  rep(i, d){
    cin >> x >> y >> c;
    if(discountedSum > R[x]+M[y]-c)
      discountedSum = R[x]+M[y]-c;
  }
  cout << discountedSum << endl;
}
