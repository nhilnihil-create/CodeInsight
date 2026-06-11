#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;


int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    int all_xor = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        all_xor ^= a[i];
    }
    for(int i = 0; i < n; i++) {
        cout << (all_xor ^ a[i]) << " ";
    }
    cout << endl;
}