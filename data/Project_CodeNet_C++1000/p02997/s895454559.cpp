#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int max = (n - 1) * (n - 2) / 2;
    if (k > max) {
        cout << "-1" << endl;
    }
    else {
        int reduce = max - k;
        cout << reduce + n - 1 << endl;
        for (int i = 2; i <= n; i++) {
            cout << 1 << " " << i << endl;
        }
        int first = 2;
        int second = 3;
        while (reduce) {
            cout << first <<  " " << second << endl;
            if (second == n) {
                first++;
                second = first + 1;
            }
            else {
                second++;
            }
            reduce--;
        }

    }
    return 0;
}