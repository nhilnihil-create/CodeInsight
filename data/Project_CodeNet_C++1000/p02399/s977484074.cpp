#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
#define MOD 1000000007
using namespace std;
signed main() {
  int a,b;cin>>a>>b;
  int p = a/b, q = a%b;
  double r = (double)a/b;
  cout<<fixed;
  cout<<p<<" "<<q<<" "<<r<<endl;
}

