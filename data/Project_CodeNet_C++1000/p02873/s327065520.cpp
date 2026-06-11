#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5e5 + 100;
typedef long long ll;
string s;
int a[N];
void expend(int pos) {
	for(int i = 1; s[pos-i] == '>'; i++) {
		a[pos-i] = max(a[pos-i], i);
	}
	for(int i = 1; s[pos+i-1] == '<'; i++) {
		a[pos+i] = max(a[pos+i], i);
	}
}
int main() {
	//freopen("01-05.txt", "r", stdin);
	cin >> s;
	s = ">" + s + "<";
	int n = s.size()-2;
	for(int i = 0; i <= n+1; i++) {
		if(s[i] == '>' && s[i+1] == '<') {
			expend(i + 1);
		}
	}
	
	ll ans = 0;
	for(int i = 1; i <= n+1; i++) {
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}