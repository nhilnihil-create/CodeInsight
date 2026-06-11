#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

typedef long long LL;

LL a, v, b, w, t;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> v >> b >> w >> t;

    LL d = abs(a-b);
    LL dd = v-w;

    if(dd*t >= d) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
