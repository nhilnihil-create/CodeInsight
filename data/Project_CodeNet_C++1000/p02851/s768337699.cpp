#include <bits/stdc++.h>
using namespace std;
#define modulo K
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000005

int main(){
	
	int N,K;
	cin>>N>>K;
	
	vector<long long> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
		A[i]%=K;
	}
	
	vector<long long> S(N+1,0);
	for(int i=1;i<=N;i++){
		S[i] += S[i-1];
		S[i] += A[i-1];
		S[i] %= K;
	}
	
	map<long long,long long> mp;
	long long ans = 0;
	
	for(int i=0;i<=N;i++){
		if(i-K>=0)mp[mod(i-K-S[i-K])]--;
		ans += mp[mod(i-S[i])];
		mp[mod(i-S[i])]++;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
