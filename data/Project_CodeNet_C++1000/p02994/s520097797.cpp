#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 100100100;

int main(){
  int n,l;
  cin >> n >> l;

  int tot = 0;
  for(int i = 1; i <=n; i++){
    tot += l+i-1;
  }

  int cnt = 1;
  int mn = inf;
  for(int i = 1; i <=n; i++){
    //int d = tot - (tot - (l+i-1));
    int d = 0;
    for(int j = 1; j <=n; j++){
      if(j == i) continue;
      d += l+j-1;
    }
    if(mn > abs(tot - d)){
      mn = abs(tot-d);
      cnt = i;
    }
  }
  cout << tot - (l+cnt-1) << endl;
    
}
