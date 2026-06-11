#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pb push_back
const int N=20005;
const int MOD=1e9+7;
 

// lower_bound - which does not compare less than val
// upper_bound - which compares greater than val
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
 int a[N],b[N],c[N];
 
int32_t main()
{
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  /* stuff you should look for
  * int overflow, array bounds
  * special cases (n=1?)
  * do smth instead of nothing and stay organized
*/

double a,v;
cin>>a>>v;
double b,w;
cin>>b>>w;
int t;
cin>>t;
double x=abs(b-a);
double y=v-w;
if(y<0)
{
cout<<"NO"<<endl;
return 0;
}
if(y<=0 && b-a>0)
{
cout<<"NO"<<endl;
return 0;
}
else
{
	double z=x/y;
	//cout<<z<<endl;
	if(z<=t)
	cout<<"YES"<<endl;
	else
	cout<<"NO"<<endl;
	
}	 
}
