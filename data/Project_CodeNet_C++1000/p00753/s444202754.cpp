#include "bits/stdc++.h"
using namespace std;

int main(){
	vector<int> a(123456*2+1,1);
	a[0]=0;
	a[1]=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==1){
			for(int j=2*i;j<a.size();j+=i){
				a[j]=0;
			}
		}
	}
	
	//for(int i=0;i<a.size();i++)if(a[i]==1)cout<<i<<" ";
	
	int n;
	while(1){
		cin>>n;
		if(n==0)break;
		int ans=0;
		for(int i=n;i<2*n;i++){
			ans+=a[i+1];
		}
		cout<<ans<<endl;
	}
	return 0;
}