#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s,t;
	cin>>s>>t;
	ll ans=0;
	for(ll i=0;i<3;i++){
		if(s[i]==t[i]){
			ans++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}