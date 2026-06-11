#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> h(n); rep(i,n) cin >> h[i];

  bool can = true;
  for(int i = n-1;i>=1;--i){
    if(h[i]-h[i-1]==-1) h[i-1]--;
    else if(h[i]-h[i-1]<-1) can = false;
  }
	
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
