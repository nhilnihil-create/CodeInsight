#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXX 1000005
#define ll signed long long int
using namespace std;
ll t , n, ans = 0, k= 0;
ll a, b;

signed main()
{
    FAST;
    cin >> a >> b;
    if(2*b >= a){
    	cout << 0 ;
    	return 0;
	}
	cout << a - 2*b;
}