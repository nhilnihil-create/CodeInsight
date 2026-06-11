#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> p(n+1);
  for(int i = 1;i<=n;i++) cin >> p[i];
  
  int k = 0;
  for(int i = 1;i<=n;i++){
    if(p[i]!=i) k++;
  }

  if(k>2){
    cout << "NO" << endl;
    return 0;
  }
  else{
    cout << "YES" << endl;
    return 0;
  }
  
  return 0;
}
