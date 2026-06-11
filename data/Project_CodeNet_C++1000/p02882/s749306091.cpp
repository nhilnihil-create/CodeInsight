#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
long double PI=acos(-1.0),ans,a,b,x,c;
int main(){
	#ifdef FILIN
		#ifndef DavidDesktop
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>a>>b>>x;
	c=x/(a*a);
	ans=90.0-atan(((c<(b/2.0))?(a*c*2.0/b/b):((a/2.0)/(b-c))))*180.0/PI;
	cout<<fixed<<setprecision(30)<<ans<<endl;
	return 0;
}
