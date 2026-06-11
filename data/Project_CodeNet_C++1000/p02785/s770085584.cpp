#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
int main() {
	ll h,m;
	cin>>h>>m;
	vector<ll>ch;
	for(ll i=0;i<h;i++){
		ll now;
		cin>>now;
		ch.push_back(now);
	}
	sort(ch.begin(),ch.end());
	ll cnt=0;
	for(ll i=0;i<h-m;i++){
		cnt+=ch[i];
	}
	cout <<cnt;
	// your code goes here
	return 0;
}