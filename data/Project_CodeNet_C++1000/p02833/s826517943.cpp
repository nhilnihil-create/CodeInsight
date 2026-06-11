#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 100100100;

//f(0) = 1
//f(1) = 1
//f(2) = 2*f(0) = 2*1
//f(3) = 3*f(1) = 3*1
//f(4) = 4*f(2) = 4*2*1;
//f(5) = 5*f(3) = 5*3*1

//f(2n+1) is odd, there's no 0;
//f(2n) = 1*2*4*....2n;
//  log5(2*10^18) ~ log5(2)+18*log5(10)
// max = 5^26

//example
//1 2 4 8 10 12 14 16 18 20 22 24 26
// mul of 5^2  = 26/25/2=0
// mul of 5^2 = 26/5/2 = 2 >>10,20
 
int main(){
  ll n;
  cin >> n;

  if(n%2 == 1){
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  for(int i = 26; i >=1; i--){
    ll div = pow(5,i);
    ans += (n/div)/2;
  }
  cout << ans << endl;
  
}
