#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define endl "\n"
#define goat() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL))
typedef long long ll;
int arr[10005];
int main() {
	goat();
	int n, k, i, x, y, z;
	ll c = 0;
	cin >> n>>k;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (i = 0; i < k; i++) {
		c += arr[i];
	}
	cout << c << endl;
}