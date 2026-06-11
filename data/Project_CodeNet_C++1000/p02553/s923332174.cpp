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
	
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll p1, p2, p3, p4;
	p1 = a * c; p2 = a * d; p3 = b * c; p4 = b * d;
	cout << max(p1, max(p2, max(p3, p4)));
}

