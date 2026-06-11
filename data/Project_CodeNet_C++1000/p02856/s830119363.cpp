#include<bits/stdc++.h>
using namespace std;
#define int long long
int sum,digit;
signed main(){
	int m,d,c;
	cin>>m;
	while(m--){
		cin>>d>>c;
		digit+=c;
		sum+=d*c;
	}
	int ans=digit-1+(sum-1)/9;
	cout<<ans;
	return 0;
} 