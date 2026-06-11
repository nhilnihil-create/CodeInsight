#include "bits/stdc++.h"

using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)

int main(){
ios_base::sync_with_stdio(0); cin.tie(0);
ll n,a,b; cin >> n  >> a >> b;
 long long res = 0;
  res += (n / (a+b)) * a + min(n % (a+b), a);
  cout << res << endl;

}
