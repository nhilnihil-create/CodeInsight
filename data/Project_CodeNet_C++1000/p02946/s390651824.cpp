#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int k,x; cin >> k >> x;

  for(int i = -k;i<=k;i++){
    int y;
    if(i<0) y = x+i+1;
    else if(i>1) y = x+i-1;
    if(i<0 || i>1) cout << y << " ";
  }
  
  return 0;
}
