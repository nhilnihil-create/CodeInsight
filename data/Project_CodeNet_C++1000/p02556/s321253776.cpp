#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],b[N],x,y;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[i]=x-y;
		b[i]=x+y;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	cout<<max(a[n]-a[1],b[n]-b[1]);
}