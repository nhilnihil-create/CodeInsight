#include<bits/stdc++.h>
using namespace std;
#define ll  long long  

void solve(){
  ll a,b;
  scanf("%lld",&a);
  b=360;
  while(b%a != 0)
    b+=360;

  printf("%lld\n",b/a);
}
int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 #ifndef ONLINE_JUDGE   
  freopen("input.txt",  "r",  stdin);
  freopen("output.txt", "w", stdout); 
 #endif
 
     int t=1; 
     // cin >> t;
     while (t--) solve();
 
     return 0;
}

