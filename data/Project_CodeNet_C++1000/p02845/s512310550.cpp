#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define int long long
#define inf 1000000007
#define LINF 100000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	map<int,int> mope;
	mope[0] = 3;
	int ans = 1;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ans *= mope[x];
		ans %= inf;
		mope[x]--;
		mope[x+1]++;
	}
	cout<<ans<<endl;
	return 0;
}