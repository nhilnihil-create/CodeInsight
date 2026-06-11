#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll mi=0;
  ll k = 100000000000000005;
  vector<int>x(n);
  rep(i,n){
    cin >> x[i];
  }
  rep(i,101){
    rep(j,n){
      mi+=(x[j]-i)*(x[j]-i);
    }
    k=min(k,mi);
    mi=0;
  }
  cout << k << endl;
    
    

  return 0;

}