#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, K;
    cin >> K >> A >> B;
    int target = K;
    while (target <= 1000) {
        if (target >= A && target <= B) {
            cout << "OK" << endl;
            return 0;
        }
        target += K;
    }
    cout << "NG" << endl;
    return 0;
}