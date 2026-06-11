#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	double k=1,c=1;
	double town[n][2]={};
	for(int i=0; i<n; i++){
		cin>>town[i][0]>>town[i][1];
	}
	for(int i=1; i<=n; i++){
		c*=i;
	}
	for(int i=1; i<n; i++){
		k*=i;
	}
	k*=2;
	double ans=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			ans+=(sqrt( ((town[i][0]-town[j][0]) *(town[i][0]-town[j][0]))+((town[i][1]-town[j][1]) *(town[i][1]-town[j][1])) ) );
			//cout<<ans<<endl;
		}
	}
	
	//cout<<k<<" "<<c<<endl;
	cout<<fixed<<setprecision(15)<<(ans*k)/c<<endl;
}