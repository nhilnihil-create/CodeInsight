#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  double l;
  cin >> l;
  double a,b,c;
  a=l/3;
  b=l/3;
  c=l/3;
  double ans=a*b*c;
  cout <<setprecision(15) << ans <<endl;

  return 0;

}