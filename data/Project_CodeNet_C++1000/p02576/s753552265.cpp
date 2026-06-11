#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

#define ll long long

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, x ,t;

	cin >> n >> x >> t;
	if ((n % x ) == 0)
	{
		cout << (n / x)* t;
	}
	else {
		cout << (n / x)*t + t;
	}
	return 0;
}