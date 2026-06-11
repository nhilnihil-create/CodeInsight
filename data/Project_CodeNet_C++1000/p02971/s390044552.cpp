#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e9 + 5;
#define INF 1000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio	
	int n;
	cin >> n;
	int a[n];
	std::vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n; i++){
		if(a[i]==v[n-1])cout << v[n-2] << endl;
		else
			cout << v[n-1] << endl;
	}
	return 0;
}






