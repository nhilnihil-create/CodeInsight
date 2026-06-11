#include<bits/stdc++.h>
using namespace std;
int n,p;
long long m,v,a[100100],qzh[100100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>v>>p;
	v=n-v;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=10-a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		qzh[i]=qzh[i-1]+a[i];
	for(int i=p+1;i<=n;i++){
		if(a[i]-a[p]>m){
			cout<<i-1<<endl;
			return 0; 
		}
		long long he=qzh[i-1]-qzh[p-1];
		he=a[i]*(i-p)-he;
		if(he>1LL*m*v){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}
