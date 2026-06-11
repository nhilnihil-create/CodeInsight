#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int h, a;
    cin >> h >> a;
    
    int ans = h / a;
    if (h > ans * a) ans++;

    cout << ans << endl;   

    return 0;
}