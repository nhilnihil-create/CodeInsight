#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 123;
#define int long long 
int n, m;
pair <int, int> a[maxn];
string s, t;
main () { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    int cur = 1;
    if(n % 2) {
    	cout << 0;
    	exit(0);
    }

    int ans = 0;
    for(int i = 1; i; i++) {
		if(cur * 5. > n * 1.) break;
		cur *= 5;
	
		int res = n / cur;
		int rem = res % 2;
		res /= 2;
		//res -= rem;
		ans += res;
    }
    cout << ans;
}


