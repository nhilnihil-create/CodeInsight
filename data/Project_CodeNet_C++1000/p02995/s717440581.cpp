#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll gcd ( ll a , ll b)
{
    if( b ==0 )
    {
        return a;
    }
    return gcd( b, a%b);
}
ll cnt( ll a, ll b , ll c)
{
    ll temp1 = a/c;
    ll temp2  = b/c;
    ll ans = temp1 - temp2;
    if( b% c ==0)
        ans++;
    return ans;
}
int main()
{
  ll a , b, c, d;
  cin>>a>>b>>c>>d;
  ll ans = b-a +1;
  ans = ans - cnt(b , a, c);

  ans = ans - cnt( b ,a,d);

  ll temp = (c*d)/gcd( c,d);

  ans += cnt( b,a,temp );

  cout<<ans;

}