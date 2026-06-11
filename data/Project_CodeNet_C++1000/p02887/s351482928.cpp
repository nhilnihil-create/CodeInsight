#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

#define MAXX 500005
#define PI 3.14159265358979323846264338327950
#define F first
#define S second
#define ll   long long int
#define mod  1000000007



int main()
{
	FAST;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	string a = "";
	a += s[0];
	for(ll i = 1; i < s.size(); i ++){
		if(s[i] != s[i-1]){
			a += s[i];
		}
	}
	cout << a.size();
}