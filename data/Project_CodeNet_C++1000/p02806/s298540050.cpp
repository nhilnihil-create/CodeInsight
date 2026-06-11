#include <iostream>
#include <cstdio>
using namespace std;

int n, ans, t[55];
string x, s[55];
int main() {
	int i;
	cin >> n;
	for(i=0; i<n; i++) cin >> s[i] >> t[i];
	cin >> x;
	for(i=0; s[i]!=x; i++);
	for(++i; i<n; i++) ans += t[i];
	cout << ans;
	return 0;
}