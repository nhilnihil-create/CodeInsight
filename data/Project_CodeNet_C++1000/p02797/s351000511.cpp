#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll n, k, s;
    cin >> n >> k >> s;

    for (int i = 0 ; i < k; i++) {
        cout << s << ' ';
    }

    if (s > n - k) {
        for (int i = 0; i < n - k; i++) cout << 1 << ' ';
    } else {
        for (int i = 0; i < n - k; i++) cout << s + 1 << ' ';
    }
    cout << endl;
}