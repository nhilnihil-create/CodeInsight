#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll X, K, D;
	cin >> X >> K >> D;
	X = abs(X);
	ll moves = min(K, X / D);
	K -= moves;
	X -= moves * D;
	cout << ((K % 2 == 0) ? X : (D - X)) << '\n';	
}