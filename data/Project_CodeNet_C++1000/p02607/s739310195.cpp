#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define endl "\n"
#define goat() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL))
typedef long long ll;
int arr[10005];
int main() {
	goat();
	int n, k, i, c = 0;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (i = 1; i <= n; i++) {
		if (i % 2 != 0 && arr[i] % 2 != 0) {
			c++;
		}
	}
	cout << c;
}