#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);


int main(){
  ll s;
  cin >> s;
  ll x1,y1,x2,y2,x3,y3;
  ll M=1000000000;
  x1=0,y1=0;
  x2=M;
  y2=1;
  x3=(M-s%M)%M;
  y3=(s+x3)/M;
  cout << x1 << " " <<y1 <<" " <<x2<<" " << y2 << " " <<x3<< " " <<y3<<endl;
}
