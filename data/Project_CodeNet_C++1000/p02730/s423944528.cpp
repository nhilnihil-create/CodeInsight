#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

bool dep(string k){
	string u=k;
	reverse(u.begin(),u.end());
	if(u!=k){
		return false;
	}
	return true;
}
int main() {
	string s;
	cin>>s;
	bool ch=true;
	ch=dep(s);
	string u;
	ll n=s.size();
	for(ll i=0;i<(n-1)/2;i++){
		u.push_back(s[i]);
	}
	if(ch){
	ch=dep(u);
	}
	string t;
	for(ll i=(n+3)/2-1;i<n;i++){
		t.push_back(s[i]);
	}
	if(ch){
	ch=dep(t);
	}
	if(ch){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	// your code goes here
	return 0;
}