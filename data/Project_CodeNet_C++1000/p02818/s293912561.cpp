#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  ll a,b,k;
  cin >> a >> b >> k;
  if(a>=k){
    cout << a-k << ' ' << b << endl;
  }
  else if(a<k&&a+b>=k){
    cout << 0 << ' ' << a+b-k << endl;
  }
  else{
    cout << 0 << ' ' << 0 << endl;
  }
  return 0;

}
