#include<bits/stdc++.h>
 
using namespace std;

#define debug(x) cout << (#x) << " is " << x << endl;
#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef unsigned long long int lli;
typedef pair<int, int> pi;


int main()
{
    int n;
    lli k, mod = 1e9+7;
    cin >> n >> k;
    int a[n];
    for(auto &x: a) cin >> x;
    
    lli ans = 0;
    for(int i=0; i<n; i++){
		lli cc=0;
		for(int j=i+1; j<n; j++){
			cc += (a[j] < a[i]);
		}
		lli cnt = ((k*(k+1))/2)%mod;
		cnt = (cnt*cc)%mod;
		ans = (ans+cnt)%mod;
		cc = 0;
		for(int j=i-1; j>=0; j--) cc += (a[j] < a[i]);
		cnt = ((k*(k-1))/2)%mod;
		cnt = (cnt*cc)%mod;
		ans = (ans+cnt)%mod;
	}
	cout << ans << endl;
 
    return 0;
}
