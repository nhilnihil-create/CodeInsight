#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3+4;
const int MOD = 1e9+7;
int mpow(int x,int y)
{
	if(y<=0) return 1;
	if(y&1) return (x*mpow(x,y-1)%MOD)%MOD;
	return mpow((x*x)%MOD,y/2)%MOD;
}

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int n;
	cin>>n;
	cout<<(mpow(10,n)-2*mpow(9,n)+mpow(8,n)+2*MOD)%MOD;
} 

// nc1*(n-1)c1*9^(n-2)

