#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	if(__builtin_popcount(n)==1)
		return cout<<"No"<<endl, 0;
	cout<<"Yes"<<endl;
	for(int i=3;i<=n;i+=2)
		cout<<i-1<<' '<<i<<'\n'<<i<<' '<<1<<'\n'<<1<<' '<<i-1+n<<'\n'<<i-1+n<<' '<<i+n<<'\n';
	cout<<n+1<<' '<<2<<'\n';
	if(n%2==0){
		int x = n&-n;
		cout<<x+1<<' '<<n<<'\n';
		cout<<n-x+n<<' '<<2*n<<'\n';
	}
}
