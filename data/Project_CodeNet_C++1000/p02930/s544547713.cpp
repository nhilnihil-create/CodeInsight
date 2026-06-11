#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int first_bit(int x) {
    int res = 0;
    while (1) {
        if (x & (1 << res))
            return res + 1;
        else
            res++;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << first_bit(i ^ j);
            if (j == n - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
    return 0;
}