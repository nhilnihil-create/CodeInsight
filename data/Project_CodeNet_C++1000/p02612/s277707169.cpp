#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long double pi = acos(-1.0); 
typedef long long ll;

struct Node {int parent, left, right;};


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << (1000 - n % 1000) % 1000 << endl;
}