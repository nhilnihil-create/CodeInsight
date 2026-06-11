#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int s  = a + b + c;
    if (s < 22) cout << "win" << endl;
    else cout << "bust" << endl;


	return 0;
}
