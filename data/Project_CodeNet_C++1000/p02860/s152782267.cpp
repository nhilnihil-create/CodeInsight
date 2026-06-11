#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 1000000007

void solve() {
	int n;cin>>n;
	string s; cin >> s;

	string a="",b="";

	for(int i=0;i<n/2;++i) {
		a+=s[i];
	}
	for(int i=n/2;i<n;++i) {
		b+=s[i];
	}

	if(a==b){
		cout << "Yes\n";
	}
	else cout << "No\n";
}


int main() {
	ios_base::sync_with_stdio(false);

	 solve();
	return 0;
} 
