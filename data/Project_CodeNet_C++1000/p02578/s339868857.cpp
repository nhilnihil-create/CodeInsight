#include<bits/stdc++.h>
using namespace std;
#define js ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
typedef long long ll;
int a[200005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	ll sum=0;
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]){
			sum+=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	cout<<sum;
	return 0;
} 