#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll mod = 1e9+7;
    int n;  cin >> n;
    ll *a = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b((int)1e6+1, 0);

    ll ans = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0)
            ans *= 3-b[0];
        else 
            ans *= b[a[i]-1]-b[a[i]];
        b[a[i]]++;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}