#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define ll long long
int main(){
	map<string,ll> m;
	string s; ll n; cin>>n; ll f=0;
	while(n--){
		cin>>s;
		f=max(f,++m[s]);
	}
	for(auto it:m){
		if(it.second==f) cout<<it.first<<endl;
	}
}
