#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N,M,X;
  cin >> N >> M >> X;
  int c[N];
  int a[N][M];
  for(int i=0;i<N;i++){
    cin >> c[i];
    for(int j=0;j<M;j++){
      cin >> a[i][j];
    }
  }
  
  ll ans = 10000000;
  ll now;
  for(int bit=0;bit<(1<<N);++bit){
    now = 0;
    vector<int> ok(M,0);
    bool flag = true;
    for(int i=0;i<N;i++){
      if(bit & (1<<i)){
	now += c[i];
	for(int j=0;j<M;j++){
	  ok[j] += a[i][j];
	}
      }
    }
    for(int j=0;j<M;j++){
      if(ok[j]<X) flag = false;
    }
    if(flag) ans = min(ans,now);
  }
  if(ans==10000000) cout << -1 <<endl;
  else cout << ans << endl;
  
}
