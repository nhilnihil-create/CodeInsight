#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;

int main() {
	int a, b;
    cin >> a >> b;
    int s = a -2 * b ;
    if (s < 0) s = 0;
    cout << s << endl;

	return 0;
}
