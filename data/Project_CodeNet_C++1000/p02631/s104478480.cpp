#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main(){
	int n,sum;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==0){
			sum=a[i]; continue;
		}
		sum^=a[i];
	}
	for(int i=0;i<n;i++){
		int k=sum^a[i];
		cout<<k<<' ';
	}
	return 0;
}