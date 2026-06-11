#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> mp;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    if (n % 3 == 0) {
        if (mp.size() > 3) {
            cout << "No\n";
            return 0;
        }
        int m = n / 3, x = 0;
        for (auto p : mp) {
            if (p.second % m) {
                cout << "No\n";
                return 0;
            }
            p.second /= m;
            while (p.second--) {
                x ^= p.first;
            }
        }
        if (x != 0) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
    }
    else if (mp.size() > 1 || mp.begin()->first != 0) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }

    return 0;
}