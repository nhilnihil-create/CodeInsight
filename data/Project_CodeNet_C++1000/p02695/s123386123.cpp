#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int n, m, q;
int A[11]{};
int a[50], b[50], c[50], d[50];
int ans = 0;

void dfs(int x) {
  if(x == n){
    int sum = 0;
    for(int i = 0; i <q; i++){
      if(A[b[i]] - A[a[i]] == c[i]) sum += d[i];
    }
    ans = max(ans,sum);
    return;
  }

  for(int i = min(A[x],m); i <= m; i++){
    A[x+1] = i;
    dfs(x+1);
  }
}



int main(){
  cin >> n >> m >> q;
  rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  A[0] = 1;
  dfs(0);
  cout << ans << endl;
  return 0;
}
