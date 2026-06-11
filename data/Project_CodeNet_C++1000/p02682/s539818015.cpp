#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;

int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  int xa = min(k,a);
  k -= xa;
  int xb = min(k,b);
  k -= xb;
  int xc = k;
  cout << xa -xc << endl;
}