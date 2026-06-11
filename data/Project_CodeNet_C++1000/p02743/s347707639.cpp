#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
long double eps = LDBL_EPSILON;
signed main() {
    long double a,b,c;
    cin >> a >> b >> c;
    if(sqrt(a)+sqrt(b)+eps*2+0.00000000000002 < sqrt(c)+eps+0.00000000000001) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

