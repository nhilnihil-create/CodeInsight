#include <iostream>
using namespace std;

int n, a[100005];
long long b, tot, ans;

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++){
        cin >> a[i];
        tot += a[i];
    }
    b = 1;
    bool flag = true;
    for (int i = 0; i <= n; i++){
        if (b < a[i]){
            flag = false;
            break;
        }
        ans += b;
        b -= a[i];
        tot -= a[i];
        b = min(b*2, tot);
    }
    if (!flag) cout << -1 << "\n";
    else cout << ans << "\n";
}
