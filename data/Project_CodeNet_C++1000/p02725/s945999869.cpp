#include <iostream>

using namespace std;

int main(){

	int k,n;
	cin>>k>>n;
	int a[n];
	int b=0;
	int ans=0;

	for(int i=0;i<n;i++){
	
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
	
		ans+=a[i]-a[i-1];
		if(a[i]-a[i-1]>=b){
		
			b=a[i]-a[i-1];
		}
	}
	if(k-a[n-1]+a[0]>b){
	
		cout<<ans;
		return 0;
	}
	ans+=k-a[n-1]+a[0];
	ans-=b;
	cout<<ans;
	return 0;
}
