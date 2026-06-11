#include <bits/stdc++.h>
using namespace std;
#include<algorithm>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll ans=0;
	for(ll i=0;i<s.size()-3+1;i++){
		string t;
		for(ll j=0;j<3;j++){
			t.push_back(s[j+i]);
		}
		if(t=="ABC"){
			ans++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}