#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int h[n];
    for(int i = 0; i < n; i++)
        cin >> h[i];
    if(k >= n)
        cout << 0;
    else {
        sort(h, h + n);
        long long ans = 0;
        for(int i = 0; i < (n - k); i++)
            ans += h[i];
        cout << ans;
    }
    return 0;
}