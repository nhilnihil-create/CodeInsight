#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


// f(0) = 1
// f(1) = 1
// f(2) = 2*f(0)
// f(3) = 3*f(1)
// f(4) = 4*f(2) = 4*2*f(0)
// f(5) = 5*f(3) = 5*3*f(1)
// f(6) = 6*f(4) = 6*4*2*f(0);
// f(7) = 7*f(5) = 7*5*3*f(1)
// f(8) = 8*f(6) = 8*6*4*2*f(0)
//...
// f(10) = 10*

// if n is odd, ans = 0;
// else
// f(2n) is multiple of n numbers;
// if n = 5, it contain one "5".
// if n = 10, it contains 5, 10
// if n = 15, it containt 5, 10, 15
// if n = 5m it contains m "5"
// devide n by 5 until n'%5 != 0;

//f(2n) contains n odd numbers.
//f(100) = 100*98*96*......90*......80......
//f(100) = 100*90*80*70*60*50*40*30*20*10*C
//       =f(10)*10
//f(1000) = f(100)*10

 int main(){
   ll n;
   cin >> n;

   if(n%2 == 1) {
     cout << 0 << endl;
     return 0;
   }
   ll ans = 0;
   ll cnt = 10;
   while(cnt <= n){
     ans += n/cnt;
     cnt *= 5;
   }
   cout << ans << endl;
 }
