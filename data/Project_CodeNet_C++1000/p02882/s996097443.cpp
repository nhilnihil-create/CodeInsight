#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    double a,b,x; cin>>a>>b>>x;
    double ans,theta;
    x/=a;
    if(x>a*b/2) theta=atan2(2*(a*b-x),a*a);
    else theta=atan2(b*b,2*x);
    ans=theta*180/pi;
    printf("%.10lf\n",ans);
	return 0;
}