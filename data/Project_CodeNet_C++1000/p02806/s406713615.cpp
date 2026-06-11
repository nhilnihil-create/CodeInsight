#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	
	int n; cin>>n; map<string,int> m; string res; int co = 0;
	for(int i = 0; i < n; i++){
		string x; int y; cin>>x>>y;
		co+=y;
		m[x] += co;
		if(i == n-1) res = x;
	}
	string s; cin>>s;
	cout<<m[res]-m[s]<<"\n";
	
	
	
	
	
}