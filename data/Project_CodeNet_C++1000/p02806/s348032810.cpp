#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

string s[52];ll t[52];
int main() {
	ll n,sum=0;
	cin>>n;
	for(ll i=0;i<n;i++){
		string x;ll y;
		cin>>x>>y;
		s[i]=x;
		t[i]=y;
		sum+=y;
	}
	for(ll i=1;i<n;i++){
		t[i]+=t[i-1];
	}
	string now;
	cin>>now;
	for(ll i=0;i<n;i++){
		if(s[i]==now){
			cout <<sum-t[i];
			return 0;
		}
	}
	// your code goes here
	return 0;
}