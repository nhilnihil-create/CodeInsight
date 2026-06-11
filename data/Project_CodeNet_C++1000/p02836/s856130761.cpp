#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) (n); i++)
#define ll long long
#define scout cout << fixed << setprecision(20)
ll INF = 9e17;
ll mod = 1e9 + 7;

int main() {
	string s; cin >> s;
	int n = s.size();
	int ans=0;
		rep(i,n/2) {
			if(s[i]!=s[n-i-1]) ans++;
			else {}
		}
	cout << ans << endl;
}