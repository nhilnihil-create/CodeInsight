#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    if(n < k) {
        cout << 1 << "\n";
        return 0;
    }
    while(1) {
        int r = n % k;
        v.push_back(r);
        n /= k;
        if(n < k) {
            v.push_back(n);
            break;
        }
    }
    cout << v.size() << "\n";
    return 0;
}