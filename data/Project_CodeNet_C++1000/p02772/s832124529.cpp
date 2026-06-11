#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  bool flag = true;
  rep(i,n){
    if(a[i]%2 == 0){
      if(a[i]%3 != 0 && a[i]%5!=0){
	flag = false;
      }
    }
  }
  
  if(flag) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
  
  return 0;
}
