#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){
  long double w,h,x,y; cin >> w >> h >> x >> y;
  int ok = 0;

  long double ans  = w*h/2.0;
  if(x == w/2.0 && y == h/2.0) ok = 1;

  cout  << setprecision(6) << ans << " " << ok << endl;
}
