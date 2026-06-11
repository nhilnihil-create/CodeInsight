#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXX 1000005
#define PI 3.14159265358979323846264338327950
#define ll signed long long int
using namespace std;
ll t , n, ans = 0, k, a[MAXX], b[MAXX], x, y, mn, mx, m = 0;
double f = 0.5;
vector<ll> v;
int main()
{
	string s;
	cin >> s;
	for(ll i = 0; i < s.size(); i+=2){
		if(s[i] != 'R' && s[i] != 'U' && s[i] != 'D'){
			cout << "No";
			return 0;
		}
	}
	for(ll i = 1; i < s.size(); i+=2){
		if(s[i] != 'L' && s[i] != 'U' && s[i] != 'D'){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
    
}