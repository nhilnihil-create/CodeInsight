#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define PI 3.141592653589793238
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(int i=0;i<(int)v.size();i++) cout<<" "<<v[i]; cout<<endl;
int power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	double a,b,h,m;
	cin>>a>>b>>h>>m;
	int minu=h*60+m;
	double hr=(double)minu*0.5;
	double mn=double(m)*6;
	double ang=max(hr,mn)-min(hr,mn);
	ang=cos(ang*PI/180.0);
	//cout<<ang<<
	double ans=2.0*a*b*ang;
	ans=a*a+b*b-ans;
	ans=sqrt(ans);
	cout<<fixed<<setprecision(20)<<ans<<endl;
}

