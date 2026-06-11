#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
  int p,q,r;
  cin >> p >> q >> r;
  if(p>=q && p>=r) cout << q+r << endl;
  else if(q>=p && q>=r) cout << p+r << endl;
  else cout << p+q << endl;
  
}
