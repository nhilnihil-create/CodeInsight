#include <bits/stdc++.h>
#define int long long int
#define gif(a,b) (a/b +(a%b?1:0))
#define pi 3.14159265358
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n";
#define float long double
using namespace std;

int32_t main()
{   
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    int n , k;
	cin >> n >> k;
	int ans = 0;
	int mod = 1000000007;
	for(int i = k; i <= n; ++i)
		ans += ( i * (n - i + 1)) % mod + 1;

  	cout << ans % mod + 1 ;
    return 0;
}
