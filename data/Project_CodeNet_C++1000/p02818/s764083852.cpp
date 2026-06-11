#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 10000005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950

#define PB push_back
#define PF push_front
#define F first
#define S second

#define fixx(n) fixed << setprecision(n)

#define ll 	 long long 

#define mod  1000000007



int main()
{
	FAST;
	ll a, b, k;
	cin >> a >> b >> k;
	ll h = a;
	a -= k;
	if(a < 0){
		a = 0;
	}
	k -= h;
	if(k < 0){
		k = 0;
	}
	if(!a && k){
		b -= k;
	if(b < 0){
		b = 0;
	}
	}
	cout << a << " " << b;
	return 0;
}