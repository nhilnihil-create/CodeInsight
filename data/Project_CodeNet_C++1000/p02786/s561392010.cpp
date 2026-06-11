#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  ll h;
  cin >> h;
  int m=0;
  while(h>1){
    h/=2;
    m++;
  }
  ll k = pow(2,m+1);
  cout << k-1 << endl;
 
  return 0;

}

