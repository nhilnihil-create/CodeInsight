#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;

int main(){
  ll a,b,n;
  cin >> a >> b >> n;
  //floor(A(x%B)/B)max=whenx%B==B-1;
  if(n<b-1)cout << floor(a*n/b)-a*floor(n/b) <<endl;
  else cout << floor(a*(b-1)/b)-a*floor((b-1)/b) << endl;
  return 0;
}
