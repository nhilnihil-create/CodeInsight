#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> p(n);
  rep(i,n) cin >> p[i];

  int cnt = 0;
  for(int i = 1;i<n-1;i++){
    if(p[i-1]>p[i] && p[i]>p[i+1]) cnt++;
    else if(p[i-1]<p[i] && p[i]<p[i+1]) cnt++;
  }

  cout << cnt << endl;
  
  return 0;
}
