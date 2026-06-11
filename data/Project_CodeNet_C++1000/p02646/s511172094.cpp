#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL a, v;
    cin >> a >> v;
    LL b, w;
    cin >> b >> w;
    LL t;
    cin >> t;

    if (v > w && abs(a-b) <= t*(v-w)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}
