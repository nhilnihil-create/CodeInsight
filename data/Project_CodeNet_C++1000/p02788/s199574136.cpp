#include<iostream>
#include<algorithm>
#include<array>
using namespace std;
const int N=2e5+10;
long long d[N],n,f,l;
array<int,2> a[N];
int main(){
	cin>>n>>f>>l;
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	sort(a,a+n);
	long long ans=0;
	for(int i=0,j=0;i<n;i++){
		while(j<n&&a[j][0]-2*f<=a[i][0]) j++;
		long long tmp=max((a[i][1]-d[i]*l+l-1)/l,0LL);
		d[i]+=tmp;
		d[j]-=tmp;
		ans+=tmp;
		d[i+1]+=d[i];
	}
	cout<<ans;
	return 0;
}
