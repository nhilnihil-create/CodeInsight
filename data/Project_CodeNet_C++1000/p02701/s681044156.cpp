#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 100005
 
#define PI   3.14159265358979323846264338327950

#define PB push_back 
#define F first
#define S second
 
#define ll 	 long long int

#define mod  1000000007


map<string, int> m;

int main()
{
	FAST;
	ll n;
	cin >> n;
	ll ans = 0;
	for(ll i = 0; i < n; i ++){
		string s;
		cin >> s;
		if(m[s] == 0){
			m[s] = 1;
			ans ++;
		}
	}
	cout << ans;
	return 0;
}