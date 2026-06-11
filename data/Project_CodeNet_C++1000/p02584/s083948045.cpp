#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;


int main(){
 ll X,k,d;
 cin>>X>>k>>d;
 ll x = abs(X);
 ll kaisuu = min (k,x/d);
 x -= kaisuu * d ;
 k -= kaisuu;
  if (k % 2 == 0) {
        cout << x << endl;
    } else {
        cout << d-x << endl;
    }
}