#include <bits/stdc++.h>

using namespace std;
#define NIL -1
#define ll long long
#define MAX 100
#define pb push_back

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);
	int x = n/2;
	int ans = 0;
	ans = arr[x] - arr[x-1];
	cout << ans << endl;
    return 0;
}
