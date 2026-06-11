#include<iostream>
#include<algorithm>
#include<array>
using namespace std;
const int N=3005;
int n,m;
array<int,2> a[N];
int b[N*2];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=m+a[i][0]-1;j>=a[i][0];j--){
			b[j]=max(b[j],b[j-a[i][0]]+a[i][1]);
		}
	}
	int ans=0;
	for(int i=0;i<=6000;i++) ans=max(ans,b[i]);
	cout<<ans;
	return 0;
}
