#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  ll S; cin >> S;
  ll x2=E9, y2=1,x3,y3;
  x3 = E9 - S%E9;
  y3 = S/E9 + 1;
  if (S==1ll*E9*E9) y3=E9, x3=0;
  cout << 0 << " " << 0 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
  //cout << abs(x2*y3-x3*y2) << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}
