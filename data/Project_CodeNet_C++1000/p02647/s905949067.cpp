#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
int n,k,a[200100],b[200100],le,ri,ok;
void move(){
	for(int i=1;i<=n;i++) b[i]=0;
	for(int i=1;i<=n;i++){
		le=max(i-a[i],1);
		ri=min(i+a[i],n);
		b[le]++;b[ri+1]--;
	}
	ok=1;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+b[i];
		if(a[i]!=n) ok=0;
	}
}
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
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=k;i++){
		move();
		if(ok) break;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
