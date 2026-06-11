#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define pr pair<int,int>
#define N 100005
#define mod 1000000007
#define INF 2147483647
using namespace std;
int main() {
	IOS;
	ll n;
	cin >> n;
	ll k = sqrt(n + 0.5);
	for (ll i = k; i >=1; i--) {
		if (n % i == 0) {
			cout << i + n / i - 2;
			break;
		}
	}
	return 0;
}