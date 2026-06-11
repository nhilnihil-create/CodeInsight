#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI   3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007



int main()
{
	FAST;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	if(n % 2){
		cout << "No";
		return 0;
	}
	for(ll i = 0; i < n / 2; i ++){
		if(s[i] != s[i+  n/2]){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}