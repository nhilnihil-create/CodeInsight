#include<bits/stdc++.h>
#define endl "\n" 
#define ll long long 
#define sp " "
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	ll q=1;//cin>>q;
	while(q--){
		int n;string s;cin>>n>>s;
		if(s.length()<=n)
			cout<<s;
		else 
			cout<<s.substr(0,n)<<"...";
	}
}
