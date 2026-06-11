
#include <bits/stdc++.h>
using namespace std;


int main() {

    int n, k, p{ 0 };
    cin >> n >> k;
    vector<int>price(n);
    for (int i{ 0 }; i < n; i++) {
        cin >> price[i];
    }

    sort(price.begin(), price.end());
    for (int i{ 0 }; i < k; i++) {
        p += price[i];
    }

    cout << p;

    return 0;
}