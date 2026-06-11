#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    int cash = 1000;
    for(int i = 1; i < n; i++) {
        int stock = 0;
        if(a[i] < a[i + 1]) stock += cash / a[i];
        cash += (a[i + 1] - a[i]) * stock;
    }

    cout << cash << endl;
    return 0;
}