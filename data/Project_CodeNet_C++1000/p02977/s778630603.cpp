#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n;
	cin>>n;
	if(__builtin_popcount(n)==1) return cout<<"No",0;
	cout<<"Yes\n";
	cout<<1<<" "<<2<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<3<<" "<<n+1<<endl;
	cout<<n+1<<" "<<n+2<<endl;
	cout<<n+2<<" "<<n+3<<endl;
	for(int i=4;i+1<=n;i+=2)
		cout<<1<<" "<<i<<endl,
		cout<<1<<" "<<i+1<<endl,
		cout<<i<<" "<<i+1+n<<endl,
		cout<<i+1<<" "<<i+n<<endl;
	if(!(n&1)){
		for(int i=2;i<n;++i){
			if(i==3) continue;
			int j=(n^i^1);
			if(j!=3 && j<n){
				cout<<i<<" "<<n<<endl;
				cout<<j<<" "<<n+n<<endl;
				break;
			}
		}
	}	
	return 0;
}