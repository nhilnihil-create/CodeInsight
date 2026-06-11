#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;


int main(){
 int a,b,c,d,e,f;
  cin >> a >> b >> c >>d;
  e = (d+a-1)/d;
  f = (c+b-1)/b;
  //cout << e << endl;
  //cout << f << endl;
  if(e>=f) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}