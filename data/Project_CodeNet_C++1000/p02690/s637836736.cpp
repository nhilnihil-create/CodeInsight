#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X;
    cin >> X;

    for (int a = -120; a <= 120; a++) {
        for (int b = -120; b <= 120; b++) {
            if (powl(a, 5) - powl(b, 5) == X) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}