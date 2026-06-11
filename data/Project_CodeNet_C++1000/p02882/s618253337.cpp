#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int>vi;
#define pb push_back
#define sc(n) scanf("%d",&n)
#define lsc(n) scanf("%lld",&n)
#define all(x) x.begin(),x.end()
#define rep(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define rev1(i,n) for(i=n;i>0;i--)
#define in insert
#define IT ::iterator
#define pr(n) printf("%d\n",n)
#define lpr(n) printf("%lld\n",n);


int main()
{
	long double a,b,x;
	cin >> a >> b >> x;
	long double ans;
	if(((a*a*b)/2)<=x)
	{
		ans=atan((2*(a*a*b-x))/(a*a*a));
	}
	else
	{
		ans=(acos(-1)/2)-atan(2*x/(a*b*b));
	}
	ans=(ans*180.0)/(acos(-1));
	cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
