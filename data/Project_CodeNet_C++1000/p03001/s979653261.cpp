#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int arr[60];
int n, p;

int main() {

	double w, h, x, y;
	cin >> w >> h >> x >> y;
	cout << setprecision(12) << w * h / 2 << " " << ((2 * x) == w
			&& (2 * y) == h )<< endl;
}
