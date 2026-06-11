#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000001


int main(){

	int N;
	cin>>N;
	
	vector<int> A(N);
	long long maxi;
	long long ans = 0LL;
	
	for(int i=0;i<N;i++){
		cin>>A[i];
		if(i==0)maxi = A[i];
		else{
			maxi = max(maxi,(long long)A[i]);
			ans += abs(maxi-A[i]);
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}