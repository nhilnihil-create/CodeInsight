#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	string s[n];
	int t[n];
	for(int i=0; i<n; i++) cin >> s[i] >> t[i];

	string x;
	cin >> x;
	int i=0, ans=0;
	while(s[i]!=x) i++;
	i++;
	for(; i<n; i++) ans+=t[i];
	cout << ans << endl;
	return 0;
}