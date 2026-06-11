#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 200010
 
#define PI   3.14159265358979323846264338327950
 
#define PB push_back 
#define F first
#define S second
 
#define ll 	long long int
 
#define mod  1000000007
 

 
int main()
{
	FAST;
	int n;
	cin >> n;
	ll ans = 0;
	while(n ){
		int x = n;
		int f = 0;
		while(x){
			x /= 10;
			f ++;
		}
		if(f % 2){
			ans ++;
		}
		n --;
	}
	cout << ans;
	return 0;
}