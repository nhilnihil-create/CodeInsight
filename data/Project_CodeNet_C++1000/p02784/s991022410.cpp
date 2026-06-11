#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e9 + 5;
#define INF 100000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;
const int MAXN = 201+5;
 
 
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	ll h,m;
	cin >> h >> m;
	ll a[m];
	ll suma = 0;
	for(ll i=0; i<m; i++){
		cin >> a[i];
		h-=a[i];
	}
	if(h<=0){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
	return 0;
}
 
//^-^