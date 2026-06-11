#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,v,b,w,t;
	cin>>a>>v>>b>>w>>t;
	long long dis=abs(a-b);
	if((v-w)*t>=dis) cout<<"YES";
	else cout<<"NO"; 
	return 0;
} 