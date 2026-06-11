#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	set<string>ch;
	for(ll i=0;i<n;i++){
		string now;
		cin>>now;
		ch.insert(now);
	}
	cout << ch.size();
	// your code goes here
	return 0;
}