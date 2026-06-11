#include <iostream>
using namespace std;
#define ll  long long  

void solve(){
  ll a,b;
  scanf("%lld",&a);
  b=360;
  while(b%a != 0)
    b+=360;
  printf("%lld",b/a);

}
int main()
{
    
     int t=1; 
     // cin >> t;
     while (t--) solve();
 
     return 0;
}
