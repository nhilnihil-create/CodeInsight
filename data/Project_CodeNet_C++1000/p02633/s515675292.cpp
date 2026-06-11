#include<bits/stdc++.h>
using namespace std;
#define ll  long long  
#define PI   3.14159265358979323846 

void solve(){
  ll a,b;
  cin>>a;
  b=360;
  while(b%a != 0)
    b+=360;

  cout<<b/a;
}
int main()
{
     
     int t=1; 
     // cin >> t;
     while (t--) solve();
 
     return 0;
}

