#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000



int main(){
	
	long long M;
	cin>>M;
	
	long long cnt=0,sum=0;
	
	for(int i=0;i<M;i++){
		long long d,c;
		cin>>d>>c;
		cnt+=c;
		sum+=c*d;
	}
	
	long long ans = 0;
	ans += cnt-1;
	ans += (sum-1)/9;
	
	cout<<ans<<endl;
	
	return 0;
}