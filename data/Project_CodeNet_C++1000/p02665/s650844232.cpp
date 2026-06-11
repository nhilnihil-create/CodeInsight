#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1e9+7,INF=mod*mod*3;//M_PI
#define rep(i,N) for(ll i=0; i<(N); i++)
#define rep1(i,N) for(ll i=1; i<(N); i++)
#define pb push_back

ll N;
ll A[100005];
ll dp[100005];

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N;
rep(i,N+1) cin>>A[i];
if(N==0){
	if(A[0]!=1){
		cout<<-1<<endl;
		return 0;
	}
}
dp[0]=1-A[0];
if(N){
	if(dp[0]<=0){
		cout<<-1<<endl;
		return 0;
	}
}
rep1(i,N+1){
	if(dp[i-1]>1e18) dp[i]=INF;
	else dp[i]=2*(dp[i-1]-A[i-1]);
	if(i<N){
		if(dp[i]<=A[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	if(i==N){
		if(dp[i]<A[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
}
ll ans=A[N];
ll son=A[N];
for(ll i=N; i>=1; i--){
	ll parent=dp[i-1]-A[i-1];
	if(son>2*parent){
		cout<<-1<<endl;
		return 0;
	}
	else if(son<parent){
		son=son+A[i-1];
	}
	else{
		son=parent+A[i-1];
	}
	ans+=son;
}
cout<<ans<<endl;


}
    
