#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> p(n); rep(i,n) cin >> p[i];
  vector<int> q(n); rep(i,n) cin >> q[i];

  vector<int> a(n); rep(i,n) a[i] = i+1;

  int cnt = 0;
  int kp,kq;
  do{
    cnt++;    
    if(p==a) kp = cnt;
    if(q==a) kq = cnt;
  }while(next_permutation(a.begin(),a.end()));

  int ans = abs(kp-kq);
  cout << ans << endl;
  
  return 0;
}
