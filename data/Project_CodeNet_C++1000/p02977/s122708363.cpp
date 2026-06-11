#include<bits/stdc++.h>
using namespace std;


int n;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if((n&-n)==n){cout<<"No\n";return 0;}
	cout<<"Yes\n";
	if(n%4==3)for(int i=1;i<2*n;++i)cout<<i<<' '<<i+1<<'\n';
	if(n%4==1&&n>1){
		for(int i=1;i<n-2;++i)cout<<i<<' '<<i+1<<'\n',cout<<n+i<<' '<<n+i+1<<'\n';
		cout<<n-2<<' '<<n+1<<'\n'
			<<1<<' '<<n-1<<'\n'
			<<1<<' '<<n<<'\n'
			<<n-1<<' '<<2*n<<'\n'
			<<n<<' '<<2*n-1<<'\n';
	}
	if(n%4==2&&n>2){
		for(int i=1;i<n-3;++i)cout<<i<<' '<<i+1<<'\n',cout<<n+i<<' '<<n+i+1<<'\n';
		cout<<n-3<<' '<<n+1<<'\n'
			<<1<<' '<<n-2<<'\n'
			<<1<<' '<<n-1<<'\n'
			<<n-2<<' '<<2*n-1<<'\n'
			<<n-1<<' '<<2*n-2<<'\n'
			<<n<<' '<<2<<'\n'
			<<2*n<<' '<<n-1<<'\n';
	}
	if(n%4==0){
		int u=n&-n,v=n^u;if(u>v)swap(u,v);
		for(int i=1;i<n-1;++i)cout<<i<<' '<<i+1<<'\n',cout<<n+i<<' '<<n+i+1<<'\n';
		cout<<n-1<<' '<<n+1<<'\n'
			<<u+1<<' '<<n<<'\n'
			<<v<<' '<<2*n<<'\n';
	}
	return 0;
}