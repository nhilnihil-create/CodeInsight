#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define pi 2*acos(0)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
using namespace std;

ll int n;

ll int po(ll int  x) {

	ll int y = x;
	for (int i = 2; i <= n; i++)
		x = (x * y) % mod;
	return x;
}

int main()
{

	io;
	
	 cin >> n;

	//PIE : 10^n - 9^n - 9^n + 8^n

	ll int a = po(10); //all possible numbers : 10 * 10 * 10 *....
	ll int b = po(9)*2 %mod;	  //numbers that doesn't contain 0. same for 9
	ll  int c = po(8);		//numbers that doesn't contain both 0 and 9

	ll int d, e, f;
	d = (a -b+ c + mod) % mod;
	
	
	cout << d;



}

