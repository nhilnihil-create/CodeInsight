#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s[0] == s[1] && s[2] == s[3] && s[2] != s[1]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
