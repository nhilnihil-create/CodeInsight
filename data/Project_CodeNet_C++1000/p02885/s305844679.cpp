#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9+7;

void solve(){
	int a,b;cin >> a >> b;
	if(2*b >= a) cout << 0 << '\n';
	else cout << a-(2*b) << '\n';
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t=1;
//	int t;cin >> t;
	while(t--) solve();
}

