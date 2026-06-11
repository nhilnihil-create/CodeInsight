#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
ll a[200001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);
	//0100 1011 0110 1101

	int n; cin >> n;
	ll tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tmp = tmp ^ a[i];
	}

	for (int i = 0; i < n; i++) {
		cout << (tmp ^ a[i]) << ' ';
	}
	cout << '\n';




}