#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
#define len(array) (sizeof(array) / sizeof(array[0]))
 
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b;
    cin >> a >> b;
    if ((a+b)%2) cout << "IMPOSSIBLE" << endl;
    else cout << (a+b)/2 << endl;
}