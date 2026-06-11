#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int temp[1000005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(k--){
		for(int i=1;i<=n;i++){
			++temp[max(1,i-a[i])];
			--temp[min(n+1,i+a[i]+1)];
		}
		int s=0;
		bool f=true;
		for(int i=1;i<=n;i++){
			a[i]=s+=temp[i];
			if(a[i]!=n){
				f=false;
			}
		}
		if(f){
			break;
		}
		memset(temp,0,sizeof(temp));
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}