#include <bits/stdc++.h>
using namespace std;

long long int solve(vector<long long int> H, long long int K){
	sort(H.begin(), H.end());
  	if(H.size()<=K) return 0;
  	long long int cost = 0;
  	for(long long int i=0; i<H.size()-K; ++i) cost += H[i];
  	return cost;
}

int main(){
	long long int N, K; cin>>N>>K;
  	vector<long long int> H(N);
  	for(int i=0; i<N; ++i) cin>>H[i];
  	cout<<solve(H, K)<<endl;
}