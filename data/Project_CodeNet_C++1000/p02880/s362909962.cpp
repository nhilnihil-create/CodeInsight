#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;

int main() {
	int n;
    cin >> n;

    bool res = false;
    rep(i, 10)rep(j, 10) {
        if(i*j == n) res = true;
    }

    if (res == true) cout << "Yes" << endl;
    else cout << "No" << endl;

	return 0;
}
