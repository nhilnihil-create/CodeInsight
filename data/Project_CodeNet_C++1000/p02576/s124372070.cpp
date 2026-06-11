#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define dou double 
#define endl "\n"

const int MOD=1e9+7;

void solve()
{
	int n,m,k;
	cin >> n >> m >> k;
	if(n>m){
		if(n%m==0){
			int t=n/m;
			cout << t*k << endl;
		}
		else{
			int t=n/m;
			cout << (t+1)*k << endl;
		}
	}
	else{
		cout << k << endl;
	}
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	solve();
	return 0;
}
