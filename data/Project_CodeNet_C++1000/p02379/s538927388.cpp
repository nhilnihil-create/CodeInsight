#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()
const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

double dist(double x1,double y1,double x2,double y2)
{
    double ans=0;
    ans+=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    ans=sqrt(ans);
    return ans;
}

int main(void)
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    printf("%lf\n",dist(a,b,c,d));
    return 0;
}
