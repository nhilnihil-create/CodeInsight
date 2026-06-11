//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
using namespace std;
typedef pair<ll,ll> P;
const ll MAX_N=1e5;
ll A[MAX_N],N;
			
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	REP(i,N)cin>>A[i];
	sort(A,A+N);
	ll ans=0;
	ans-=A[0];
	ans+=A[N-1];
	REP(i,N-2){
		ll a=A[i+1];
		ans+=llabs(a);
	}
	cout<<ans<<endl;
	ll ite=1;
	FOR(i,1,N-1){
		if(A[i]<0){
			ite++;
		}else{
			break;
		}
	}
	FOR(i,ite,N-1){
		cout<<A[0]<<' '<<A[i]<<endl;
		A[0]-=A[i];
	}
	REP(i,ite){
		cout<<A[N-1]<<' '<<A[i]<<endl;
		A[N-1]-=A[i];
	}
}