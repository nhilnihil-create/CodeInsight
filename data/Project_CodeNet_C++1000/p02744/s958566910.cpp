#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include<map>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1;i <=n;i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
const ll MOD =  1000000007;
const ll INF =  1LL << 60;
ll n, m, x, y,z,w,h, sum= 0, ans = 0;
void dfs(string s,char mx) {
	if (s.size() == n) cout << s << endl;
	else {
		for (char c = 'a'; c <= mx; c++) {
			if (mx == c) dfs(s + c, mx + 1);
			else dfs(s + c, mx);
		}
	}
}
int main() {
	cin >> n;
	dfs("",'a');
}