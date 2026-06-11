#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;
  int k = (a+b)/2;
  bool test = true;
  if(2*k!=a+b) test = false;

  if(!test) cout << "IMPOSSIBLE" << endl;
  else cout << k << endl;
  
  return 0;
}
