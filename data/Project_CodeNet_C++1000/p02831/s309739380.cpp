#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000009
#define pi 2*acos(0)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
using namespace std;


int main()
{

	io;
	
	ll int a, b; cin >> a >> b;

	ll int gcd_ = gcd(a, b);
	ll  int pro = a * b;
	//gcd * lcm = a* b
	ll int ans = pro / gcd_;
	cout << ans;
}

