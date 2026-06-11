#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  ll a,b,c;
  cin >> a >> b >> c;

  if(a+b+2*(long double)sqrtl(a*b)<c) cout << "Yes";
  else cout << "No";
}