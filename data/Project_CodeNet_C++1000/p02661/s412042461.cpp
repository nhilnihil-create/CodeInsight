#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  int ans;
  if(n%2 == 1){
    int l = a[n/2];
    int r = b[n/2];
    ans = r-l+1;
  }
  else{
    int l2 = a[n/2-1]+a[n/2];
    int r2 = b[n/2-1]+b[n/2];
    ans = r2-l2+1;
  }
  cout << ans << endl;
  
  return 0;
}
