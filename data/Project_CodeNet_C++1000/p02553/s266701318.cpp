#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
ll a1 =a*c;
ll a2 = a*d;
ll a3 = b*c;
ll a4 = b*d;
 ll ans1 =max(a1,a2);
 ll ans2 = max(a3,a4);
 ll ans = max(ans1,ans2);
 cout<<ans<<endl;
 return 0;
}

