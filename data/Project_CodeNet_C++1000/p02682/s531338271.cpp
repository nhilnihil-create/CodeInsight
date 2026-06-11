#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   /// https://ideone.com/Fd5s8n
  ll a,b,c,k;
  cin>>a>>b>>c>>k;
  ll ans =0;
  if(k<a)
    ans+= k;
  else if(k==a)
    ans +=a;
  else{
    ans +=a;
    k-=a;
    if(k>b){
    k-=b;

    ans += -k;
  }
  }
 cout << ans << endl;
    return 0;

}
