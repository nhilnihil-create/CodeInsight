#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
int n;
long long k,to,a[200100],f[200100],l,r,kt,v;
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
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],to+=a[i];
	for(int i=1;i<=n;i++) cin>>f[i];
	sort(a+1,a+n+1);
	sort(f+1,f+n+1);
	reverse(f+1,f+n+1);
	if(to==k){
		cout<<0<<endl;
		return 0; 
	}
	for(int i=1;i<=n;i++) r=max(r,a[i]*f[i]);
	while(l<r){
		kt=k;
		v=(l+r)>>1;
		for(int i=1;i<=n;i++){
			if(a[i]*f[i]>v) kt-=(a[i]-v/f[i]);
		}
		if(kt<0) l=v+1;
		else r=v;
	}
	cout<<l<<endl;
	return 0;
}
