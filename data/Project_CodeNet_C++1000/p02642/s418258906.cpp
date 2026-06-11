#include <iostream>
using namespace std;

int n, a[200005], v[1000005], mx;

int main() {
    cin >> n;
    for(int i =1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for(int i = 1; i <= n; i++)
        for(int j = a[i]; j <= mx; j += a[i])
            v[j]++;

    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(v[a[i]] == 1)
            ans++;
    cout << ans;
}
