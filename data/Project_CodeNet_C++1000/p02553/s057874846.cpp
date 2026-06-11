#include<iostream>
#include<algorithm>
typedef long long ll;

using namespace std;

ll a, b, c, d;
ll a1[4];

int main() {
	cin >> a >> b >> c >> d;
	a1[0] = a * c; a1[1] = a * d; a1[2] = b * c; a1[3] = b * d;
	sort(a1, a1 + 4);
	cout << a1[3] << '\n';
}