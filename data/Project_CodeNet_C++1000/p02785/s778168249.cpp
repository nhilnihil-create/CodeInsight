#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}	
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<min(n,k);i++){
		v[i]=0;
	}
	long long int ans=0;
	for(int i=0;i<n;i++){
		ans+=v[i];
	}
	cout<<ans<<endl;
	return 0;
}
