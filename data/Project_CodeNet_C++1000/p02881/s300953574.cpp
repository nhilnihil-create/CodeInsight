#include <iostream>
#include<cmath>
#define ll long long
using namespace std;
#define rep2(i,a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
    ll n;
  cin >> n;
  ll ans = 1000000000005;
  ll m = (ll)sqrt(n);
  rep2(i, 1, m + 1) {
    if (n % i == 0) ans = min(ans, (i - 1) + (n / i - 1));
  }
  cout << ans << endl;
}
