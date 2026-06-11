#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
const int INF = 1e9 + 7;

int main(){
    ///preprocessing
    #ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    #endif // ONLINE_JUDGE
    fio;
    ///code below
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max({a * c, a * d, b * c, b * d});
}
