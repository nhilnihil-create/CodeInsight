#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

#define MAXX 500005
#define PI 3.14159265358979323846264338327950
#define F first
#define S second
#define ll   long long int
#define mod  1000000007



int main()
{
	FAST;
	ll t;
	
		ll n, m;
		cin >> n >> m;
		if(n <= 2 * m){
			cout << 0;
		}
		else{
			cout << n - (2*m);
		}
		cout << endl;
	
}