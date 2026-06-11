#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 100100100;

int main(){
  int n,l;
  cin >> n >> l;

  int tot = (l-1)*n+n*(n+1)/2;
  int cnt = 1;

  int mn = inf;
  for(int i = 1; i <=n; i++){
    if(mn >= abs(l+i-1)){
      mn = abs(l+i-1);
      cnt = i;
    }
  }
  cout << tot - (l+cnt-1) << endl;
    
}
