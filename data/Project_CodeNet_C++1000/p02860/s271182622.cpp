#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

string solve() {
	int n;cin>>n;
	string s; cin >> s;
	if(n&1) {
		return "No";
	}

	for(int i=0;i<n/2;++i) {
		if(s[i]!=s[i+n/2]) return "No";
	}

	return "Yes";
}


int main() {
	ios_base::sync_with_stdio(false);

	cout <<  solve();
	return 0;
} 
