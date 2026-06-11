#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int k=0;
	int n;cin>>n;
	map<string,int> s;
	rep(i,n){
		string a; cin>>a;
		s[a]+=1;
		k=max(k,s[a]);
	}
	for( auto& p:s){
		if(p.second>=k){
			cout<<p.first<<endl;
		}
	}
}
		