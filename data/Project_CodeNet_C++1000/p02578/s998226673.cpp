#include <iostream>
using namespace std;

int n, a[200005];
long long ans;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        if(mx > a[i]) {
            ans += (mx - a[i]);
            a[i] = mx;
        }
        mx = max(a[i], mx);
    }
    cout << ans;
}
