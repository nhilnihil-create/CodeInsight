#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)


void aryan_p() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	return;
}

vi x;

void factorize(long long n)
{

	int count = 0 ;
	// count the number of times 2 divides
	while (!(n % 2)) {
		n >>= 1; // equivalent to n=n/2;
		count++;
	}

	// if 2 divides it
	if (count)
		x.pb(2);

	// check for all the possible numbers that can
	// divide it
	for (long long i = 3; i <= sqrt(n); i += 2) {
		count = 0;
		while (n % i == 0) {
			n = n / i;
			count++;
		}
		if (count)
			x.pb(i);
	}

	// if n at the end is a prime number.
	if (n > 2)
		x.pb(n);

	return;
}




int32_t main() {


	int a, b;
	cin >> a >> b;

	int val = __gcd(a, b);

	//Factorize Val
	factorize(val);
	cout << x.size() + 1;





	return 0;
}