#include <bits/stdc++.h>
#define ll long long
#define PI 3.14159265358979323846
using namespace std;
int main()
{
 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll aa =max(a*c,a*d);
  ll bb = max(b*c,b*d);
  ll ans = max(aa,bb);
  cout << ans << endl;





}
