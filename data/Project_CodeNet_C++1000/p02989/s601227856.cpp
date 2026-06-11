#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> d(n+1,-1); for(int i = 1;i<=n;i++) cin >> d[i];

  sort(d.begin(),d.end());
  /*cout << "sorted" << endl;
  for(int i = 1;i<=n;i++) cout << d[i] << " ";
  cout << endl;*/
  
  int left = d[n/2];
  int right = d[n/2+1];
  int ans = right-left;
  
  //printf("l: %d r: %d\n",left,right);
  cout << ans << endl;
  
  return 0;
}
