#include <bits/stdc++.h>
using namespace std;
#include<algorithm>
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;string s;
	cin>>n>>s;
	ll ans=0;
	for(ll i=0;i<n-2;i++){
		string t;
		for(ll j=i;j<i+3;j++){
			t.push_back(s[j]);
		}
//		cout <<t<<endl;
		if(t=="ABC"){
			ans++;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}