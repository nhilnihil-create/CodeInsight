#include<bits/stdc++.h>
using namespace std;
#define ll long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a;
	cin >> a;
	cout << a + pow(a, 2) + pow(a, 3) << endl;
}