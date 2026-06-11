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
 
#define ll 	  long long 
 
#define mod  1000000007



int main()
{
	FAST;
	int n, k;
	cin >> n >> k;
	int a[max(n, k) + 6] = {0};
	ll int x = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		x += a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	for(int i = 0; i < k; i ++){
		x -= a[i];
	}
	if(k >= n){
		x = 0;
	}
	cout << x;
	return 0;
}