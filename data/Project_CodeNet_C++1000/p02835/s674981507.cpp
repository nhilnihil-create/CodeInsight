#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        cin >> A;
        sum += A;
    }
    if (sum >= 22) cout << "bust" << endl;
    else cout << "win" << endl;
    return 0;
}