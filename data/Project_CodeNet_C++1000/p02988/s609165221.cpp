#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, no_sat = 0;
    cin >> n;
    int array[3];
    cin >> array[0] >> array[1] >> array[2];
    for (int i = 0; i <= n - 3; i++) {
        if (min(min(array[0], array[1]), array[2]) != array[1] && max(max(array[0], array[1]), array[2]) != array[1]) {
            no_sat++;
        }
        array[0] = array[1];
        array[1] = array[2];
        cin >> array[2];
    }
    cout << no_sat;
}

