#include  <bits/stdc++.h>
using namespace std;
#define int long long
#define forr(i, n) for(int i = 0;i < (int)n; i++)
#define deb(x) cout<<#x<<" " <<x<<"\n";
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define mp make_pair
#define test int tests;cin >> tests;while(tests--)
#define endl "\n"
const int INF = 2e9;
int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("inputa.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	if(n&1){
		cout<<(double)(((n+1)/2.0)/(double)n);
	}else{
		cout<<(double)((n/2.0)/(double)n);
	}	
	return 0;
}