#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector< int > 
#define pii pair< int, int >
#define mii map< int , int > 
#define F(start,stop) for(int i=start; i<stop; i++)
#define FRev(start,stop) for(int i=start; i>=stop; i--)
#define MOD1 1000000007
#define MOD2 998244353

int main()
{

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	IOS

	ll n;
	cin >> n;
	ll a[n];
	ll b[n];

	F(0,n) cin >> a[i] >> b[i];

	sort(a, a+n);
	sort(b, b+n);
	ll med_a , med_b;
	if(n%2 != 0){
		med_a = a[n/2];
		med_b =  b[n/2];
	}else{
		med_a = a[n/2] + a[(n-1)/2];
		med_b = b[n/2] + b[(n-1)/2];
	}
	cout << med_b - med_a + 1 << endl;
}