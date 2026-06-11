#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+4;


int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<max({b*d,a*c,a*d,b*c});
} 

