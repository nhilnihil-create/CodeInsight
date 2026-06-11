#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

long long pot5(int n) {
    return 1ll * n * n * n * n * n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int x;
    cin >> x;
    
    int a, b;
    bool stop = false;
    for (a = 1; a <= 120; a++) {
        for (b = -119; b <= 119; b++) {
            if (pot5(a) - pot5(b) == x) {
                stop = true;
                break;
            }
        }
        if (stop) break;
    }
    cout << a << " " << b << endl;
    

	return 0;
}