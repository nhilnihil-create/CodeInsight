#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, d;
    cin >> n >> d;
    
    int resp = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (sqrt(a * 1ll * a + b * 1ll * b) <= d) {
            resp++;
        }
    }
    cout << resp << endl;

	return 0;
}