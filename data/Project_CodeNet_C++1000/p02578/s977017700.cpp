#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    long long ans = 0;
    int max_height = 0;
    for (int i = 0; i < n; i++) {
        max_height = max(max_height, A[i]);
        int stool = max_height - A[i];
        ans += stool;
    }        
    cout << ans << endl;

	return 0;
}