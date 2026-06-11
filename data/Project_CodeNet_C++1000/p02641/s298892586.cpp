#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>
typedef long long ll;
using namespace std;

int arr[107];
const ll inf = 1000000001;

int main() {
    int x, n; cin >> x >> n;
    
    set<int>s;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        s.insert(a);
    }

    ll dif = inf;
    ll ans = inf;
    for (int i = -150; i <= 150; ++i) {
        if (s.count(i))
            continue;
        int di = abs(x - i);
        if (di < dif) {
            dif = abs(x - i);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
