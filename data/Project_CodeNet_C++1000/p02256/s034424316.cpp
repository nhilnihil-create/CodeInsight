#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
using namespace std;
// euclidean
int gcd(int x,int y) {
  if(x<y)swap(x,y);
  if (y==0) {
    return x;
  } else {
    x %= y;
    gcd(x,y);
  }
}

signed main() {
  int x,y; cin>>x>>y; cout<<gcd(x,y)<<endl;
}

