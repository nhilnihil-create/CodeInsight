//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
const ll MAX_N=3e5;
ll N,f[MAX_N],C[MAX_N+1],D[MAX_N+1],psmD[MAX_N+2],psmkD[MAX_N+2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	REP(i,N){
		ll a;
		cin>>a;
		C[a]++;
	}
	REP(i,N){
		D[C[i+1]]++;
	}
	psmD[0]=psmkD[0]=0;
	REP(i,N+1){
		psmD[i+1]=psmD[i]+D[i];
		psmkD[i+1]=psmkD[i]+i*D[i];
	}
	REP(x,N){
		f[x]=(psmkD[x+2]+(x+1)*(psmD[N+1]-psmD[x+2]))/(x+1);
	}
	REP(x,N)f[x]*=-1;
	REP(i,N){
		ll ans=upper_bound(f,f+N,-(i+1))-f;
		if(ans==0){
			cout<<0<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}
