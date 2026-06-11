#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],cnt[N];
bool calc(int n){
	for(int i=1;i<=n;++i) cnt[i]=0;
	for(int i=1;i<=n;++i){
		int l=max(i-a[i],1),r=min(i+a[i],n);
	//	cout<<i<<" "<<l<<" "<<r<<endl;
		cnt[l]++;cnt[r+1]--;
	}
	for(int i=1;i<=n;++i){
		cnt[i]+=cnt[i-1];
		a[i]=cnt[i];
	}
	for(int i=1;i<=n;++i)
		if(a[i]<n) return 0;
	return 1;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=k;++i)
		if(calc(n)) break;
	for(int i=1;i<=n;++i)
		cout<<a[i]<<" ";
	return 0;
}