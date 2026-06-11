#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string t; cin>>t;
	int k=t.size();
	string s;
	rep(i,k){
		if(t[i]=='?') s+="D";
		else s+=t[i];
	}
	cout<<s<<endl;
}