#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n,m,k;
  cin >> n >> m >> k;
  long a[n],b[m];
  rep(i,n)cin >> a[i];
  rep(i,m)cin >> b[i];
  long suma = 0,sumb = 0;
  long ka = 0,kb = 0;
  long ai = 0;
  rep(i,n){
    if(ka+a[i]<=k){
      suma++;
      ka += a[i];
      ai++;
    }
    else break;
  }
  long bi = 0;
  rep(i,m){
    if(ka+b[i]<=k){
      suma++;
      ka += b[i];
      bi++;
    }
    else break;
  }
  long ans = suma;
  long nsuma = suma;
  while(ai>0){
    ka -= a[ai-1];
    ai -= 1;
    nsuma -= 1;
    while(ka+b[bi]<=k && bi<m){
      ka += b[bi];
      nsuma += 1;
      bi++;
    }
    if(ans<nsuma)ans = nsuma;
  }
  cout << ans << endl;
  return 0;
}