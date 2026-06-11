#include <iostream>
#include <vector>
#include <algorithm>

#define MAX(X,Y) ((X)>(Y)?(X):(Y))

using namespace std;

int main(void){
  int n,m,ans;
  vector<int> h,f;
  
  cin >> n >> m;
  h.push_back(0); f.push_back(0); // [0]
  for (int i=0; i<n; i++){
    int t; cin >> t;
    h.push_back(t);
    f.push_back(1);
  }
  for (int i=0; i<m; i++){
    int a,b; cin >> a >> b;
    if (h[a]>=h[b]) f[b]=0;
    if (h[a]<=h[b]) f[a]=0;
  }
  ans = 0;
  for (int i=1; i<=n; i++){
    if (f[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}