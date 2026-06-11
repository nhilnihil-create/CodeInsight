#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) (n); i++)
#define ll long long
ll INF=9e17;

int main() {
	string s,t;
	cin >> s >> t;
	int ans = 0;
	rep(i,3) {
		if(s[i]==t[i]) ans++;
	}
	cout << ans << endl;
}