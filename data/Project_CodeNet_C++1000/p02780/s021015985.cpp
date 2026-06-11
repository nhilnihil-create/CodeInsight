#include <bits/stdc++.h>
using namespace std;
typedef double d;
const int mod=1e9+7;
const int N=2e5+5;
d arr[N];
int main(){
	int n,k;cin>>n>>k;
	d mx=0.0;
	d cur=0.0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i]=(arr[i]+1.0)/2.0;
	}
	for(int i=0;i<k;i++){
		mx+=arr[i];
	}
	cur=mx;
	for(int i=k;i<n;i++){
		cur-=arr[i-k];
		cur+=arr[i];
		mx=max(mx,cur);
	}
	cout<<setprecision(9)<<fixed<<mx;
	return 0;
}