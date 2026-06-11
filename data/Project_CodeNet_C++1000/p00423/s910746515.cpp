#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, a, b;
    while (cin >> N, N) {
        int p1 = 0, p2 = 0;
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            if (a > b) {
                p1 += a + b;
            } else if (a < b) {
                p2 += a + b;
            } else {
                p1 += a;
                p2 += b;
            }
        }
        cout << p1 << " " << p2 << endl;
    }
    return 0;
}