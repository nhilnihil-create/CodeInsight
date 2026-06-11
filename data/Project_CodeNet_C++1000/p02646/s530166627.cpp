//In the name of Allah :)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10, MOD = 1e9 + 7, INF = 1e9 + 5;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long a, b, v, w, t;
	cin >> a >> v >> b >> w >> t;
	if(w >= v){
		cout  << "NO\n";
		return 0;
	}	
	if(abs(a - b) <= (v - w) * t){
		cout << "YES\n";
		return 0;
	}

	cout << "NO\n";
}
