#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using P = pair<int,int>;
static const ll INF = 1000000000000000000;
static const ll MOD = 1000000007;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int ans = max(0, c - (a - b));
	cout << ans << endl;
	return 0;
}

