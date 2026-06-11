#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n;
	cin>>n;
	int k=7;
		for(int i=1; i<=n; i++){
			k%=n;
			if(k==0){cout<<i; return 0;}
			k=10*k+7;
		}
		
	cout<<-1<<endl;
}