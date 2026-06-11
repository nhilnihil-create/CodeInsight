#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  ll n,a,b;
  cin >> n >> a >> b;
  if(a==0){
    cout << 0 << endl;
  }
  else{
    if(b==0){
      cout<< n << endl;
    }
    else{
      ll k=n/(a+b);
      ll o=n%(a+b);
      if(o<=a){
        cout<< k*a+o << endl;
      }
      else{
        cout << k*a+a << endl;
      }
    }
  }
  return 0;

}
