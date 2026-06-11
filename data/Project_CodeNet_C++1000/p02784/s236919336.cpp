#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int h,n; cin >> h >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(),a.end());

  rep(i,n){
    h-=a[i];
  }

  bool flag = false;
  if(h<=0) flag = true;

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
