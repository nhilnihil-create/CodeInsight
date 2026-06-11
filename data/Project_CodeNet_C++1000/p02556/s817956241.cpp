#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+4;
const int MOD = 1e9+7;

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int n;
	cin>>n;
	vector<int> a,b;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		a.push_back(x+y);
		b.push_back(x-y);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	cout<<max(abs(a[n-1]-a[0]),abs(b[0]-b[n-1]));
} 

