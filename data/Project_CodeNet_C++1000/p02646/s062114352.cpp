#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, V, W, T;
    cin >> A >> V;
    cin >> B >> W;
    cin >> T;

    long long diff_distance = abs(A - B);
    long long relative_speed = V - W;

    if (diff_distance <= relative_speed * T) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}