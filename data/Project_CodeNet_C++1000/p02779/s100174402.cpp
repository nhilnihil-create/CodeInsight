#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int gcd(int a,int b){
	return (b==0)?a:gcd(b,a%b);
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	unordered_map<int,int>mp;
	while(t--){
		int a;
		cin>>a;
		++mp[a];
	}
	for(auto x:mp){
		if(x.second%2==0){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
