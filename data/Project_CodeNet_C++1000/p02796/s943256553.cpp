#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
int n,x,l;
long long lef;
pair<long long,long long> sg[100100];
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
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>l;
		sg[i]=make_pair(x+l,x-l);
	}
	sort(sg+1,sg+n+1);
	lef=-1e18;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(lef<=sg[i].second){
			lef=sg[i].first;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
