#include<bits/stdc++.h>
using namespace std;

signed main(){
	long long n;	cin>>n;
	long long D=0, sum=0;
	
	for(long long i=0;i<n;i++){
		long long d,c;	cin>>d>>c;
		D+=c;
		sum+=d*c;
	}

	cout<<D-1 + ((sum-1)/9)<<endl;

	return 0;
}
