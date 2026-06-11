#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<string> s(n);
	vector<int> t(n);
	string x;
	
	int ans = 0;
	for(int i=0; i<n; i++){
		cin >> s[i] >> t[i];
		ans += t[i];
	}

	cin >> x;
	for(int i=0; i<n; i++){
		ans -= t[i];
		if(s[i]==x) break;;
	}
	cout << ans << '\n';
	return 0;
}

