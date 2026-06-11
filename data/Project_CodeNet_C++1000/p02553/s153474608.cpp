#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define mod 1000000007
ll min(ll a, ll b) {
	if (a < b)
		return a;
	else
		return b;
}
bool compare(int a, int b) {
	return a > b;
}
int main() {
	fio;
	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	cout << max((a * x), max((a * y), max((b * x), (b * y))));
	return 0;
}