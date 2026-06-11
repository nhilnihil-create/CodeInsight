#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1;

int main()
{
  ll a,b,c,d;
  scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
  ll ans=max(max(a*c,a*d),max(b*c,b*d));
  printf("%lld",ans);
}
