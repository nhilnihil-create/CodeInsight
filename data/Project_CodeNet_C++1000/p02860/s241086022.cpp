#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	string s;
	cin>>s;
	string t;
	for(ll i=0;i<n/2;i++){
		t.push_back(s[i]);
	}
	t=t+t;
	if(s==t){
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}