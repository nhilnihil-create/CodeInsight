#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	vector<int> t(n);
	string x;
	for(int i=0; i<n; i++){
		cin >> s[i] >> t[i];
	}
	cin >> x;

	bool sleep = false;
	int ans = 0;
	for(int i=0; i<n; i++){
		if(sleep) ans += t[i];
		if(s[i]==x) sleep = true;
	}
	cout << ans << '\n';
	return 0;
}

