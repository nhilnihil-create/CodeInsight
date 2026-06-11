#include <bits/stdc++.h>
     
using namespace std;
     
int main() {
    int n;
    cin >> n;
    int max = 0;
    int scnd_max = 0;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > max) {
            scnd_max = max;
            max = x;
        } else if (x > scnd_max) {
            scnd_max = x;
        }
        vals[i] = x;
    }
    for (int i = 0; i < n; i++) {
        if (vals[i] == max) {
            cout << scnd_max << '\n';
        } else {
            cout << max << '\n';
        }
    }
}