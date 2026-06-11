#include<bits/stdc++.h>
using namespace std;

main(){
	int d,t,s;
	cin>>d>>t>>s;
	
	if((d+s-1)/s <= t) cout<<"Yes";
	else cout<<"No";
}