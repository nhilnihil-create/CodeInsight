#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+5]={0};
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	long long ans=1000;
	for(int i=1;i<n;i++){
	    if(a[i]<a[i+1]){
	        ans+=(ans/a[i])*(a[i+1]-a[i]);
	    }
	}
	cout<<ans<<endl;
}
