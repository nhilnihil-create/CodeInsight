#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
int a[214514],sum[214514];
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]--;
	}
	map<int,int> mope;
	int ans = 0;
	mope[0] = 1;
	for(int i=1;i<=n;i++){
		sum[i] = sum[i-1] + a[i];
		if( i >= k ) mope[ sum[i-k] % k ] --;
		ans += mope[ sum[i] % k ];
		//cout << mope[ sum[i] % k ] <<endl;
		mope[ sum[i] % k ] ++;
	}
	cout<<ans<<endl;
	return 0;
}