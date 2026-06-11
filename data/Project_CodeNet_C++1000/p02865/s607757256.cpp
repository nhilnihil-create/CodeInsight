// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma comment(linker,"/stack:200000000")
#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0.0)
#define print(x) return cout<<x<<endl,0
#define watch(x) cerr<<#x<<"-> "<<x<<endl
#define CLEAR(x,val) memset(x,val,sizeof(x))
// #define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int INF = 1000000000;
const int MOD = 1000000007;

signed main()
{	
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	cout<<n/2-(n%2==0)<<endl;
	return 0;
}