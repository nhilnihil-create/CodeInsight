#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 100005
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
	int n;
	cin >> n;
	int a[n+5];
	ll x = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(i % 2 == 0){
			x += a[i];
		}
		else{
			x -= a[i];
		}
		
	}
	cout << x << " ";
	for(int i = 0; i < n-1; i ++){
		x = 2*a[i] - x;
		cout << x  << " ";
	}
	return 0;
	
}