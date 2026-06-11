#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;



int main() {
  int n, m, sum=0;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
    sum+=a[i];
  }
  
  
  string ans="No";
  int cnt=0;
  rep(i,n){
    if(a[i]*4*m >= sum) cnt++;
    if(cnt >= m){
      ans="Yes";
      break;
    }
  }
  
  cout << ans << endl;
  return 0;
}
