#include<bits/stdc++.h>
using namespace std;
int main(){
 	int n;
	cin>>n;
	long long h[n];
	int ans=0,k=0;
	for(int i=0;i<n;i++){
		cin>>h[i];
		if(i==0){
			continue;
		}
		else{
			if(h[i]<=h[i-1]){
				k++;
			}
			else{
				ans=max(ans,k);
				k=0;
			}
		}
	}
	ans=max(ans,k);
	cout<<ans<<endl;
}
