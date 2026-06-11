#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << max({ a*c,a*d,b*c,b*d });
	return 0;
}