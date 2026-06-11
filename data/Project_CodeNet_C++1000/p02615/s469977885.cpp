#include <iostream>
#include <algorithm>
using namespace std;

int n, a[200005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1, greater<int>());
    long long ans = 0;
    for(int i = 2; i <= n; i++)
        ans += 1LL*a[(i+1)/2];
    cout << ans;
}
