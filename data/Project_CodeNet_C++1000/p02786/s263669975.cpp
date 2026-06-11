#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 500005
 
#define PI   3.14159265358979323846264338327950
 
#define PB push_back 
#define PF push_front
#define F first
#define S second
 
#define fixx(n) fixed << setprecision(n)
 
#define ll 	  long long int
 
#define mod  1000000007



int main()
{
	FAST;
	ll n;
	cin >> n;
	ll  k = 0;
	ll  h = 1;
	while(n >= 1){
		
		k += h;
		h *= 2;
		n /= 2;
	}
	cout << k;
	return 0;
}