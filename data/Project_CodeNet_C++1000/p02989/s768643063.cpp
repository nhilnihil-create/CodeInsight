#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>ch;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		ch.push_back(now);
	}
	sort(ch.begin(),ch.end());
	ll l=ch[n/2-1];
	ll r=ch[n/2];
	cout << r-l;
	// your code goes here
	return 0;
}