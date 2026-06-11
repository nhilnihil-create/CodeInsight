#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 3e5 + 7;



int main() {
	fastIO;
	int n;
	cin >> n;
	cout << n / 2 + (n & 1);
}