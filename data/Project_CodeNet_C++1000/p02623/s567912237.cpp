#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef unsigned long ul;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;

int main() {
	
	ll N,M,K;
	cin>>N>>M>>K;
	
	vl A(N+1), B(M+1);
	A[0]=B[0]=0;
	
	for(int i=1; i<=N; ++i) {
		cin>>A[i];
		A[i]+=A[i-1];
	}
	
	for(int i=1; i<=M; ++i) {
		cin>>B[i];
		B[i]+=B[i-1];
	}
	
	int ans=0;
	
	if(N<M) {
		for(int i=0; i<=N; ++i) {
			if(K-A[i]<0) continue;
			auto it = upper_bound(B.begin(),B.end(),K-A[i]);
			--it;
			ans=max(ans, int(it-B.begin())+i);
		}
	}
	
	else {
		for(int i=0; i<=M; ++i) {
			if(K-B[i]<0) continue;
			auto it = upper_bound(A.begin(),A.end(),K-B[i]);
			--it;
			ans=max(ans, int(it-A.begin())+i);
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
