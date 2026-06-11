#include <bits/stdc++.h>
using namespace std;
int n;
int x[200010],y[200010];
int a[200010],b[200010];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		a[i]=x[i]-y[i];
		b[i]=x[i]+y[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	cout<<max(a[n-1]-a[0],b[n-1]-b[0])<<endl;
	return 0;
}