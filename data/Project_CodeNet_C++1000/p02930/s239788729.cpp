#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
int n;
int LG[600];
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
	int it=1;
	for(int i=1;i<=512;i*=2){
		LG[i]=it;
		it++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cout<<LG[lowbit((i^j))]<<' ';
		}
		cout<<endl;
	} 
	return 0;
}
