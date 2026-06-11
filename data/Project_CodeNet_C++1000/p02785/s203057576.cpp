#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, k;
  cin >> n >> k;
  ll ans=0;
  ll h[n];
  if(n<=k){
    cout << 0 << endl;
    return 0;
  }
  for(int i=0; i<n; i++){
    cin >> h[i];
  }
  sort(h, h+n);
  for(int i=0; i<n-k; i++){
    ans += h[i];
  }
  cout << ans << endl;
  return 0;
}
