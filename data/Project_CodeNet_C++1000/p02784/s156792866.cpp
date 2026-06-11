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
	int h, a;
	cin >> h >> a;
	int b[a+4];
	ll x = 0;
	for(int i = 0; i < a; i ++){
		cin >> b[i];
		x += b[i];
	}
	if(x >= h){
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}