#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X;
    cin >> X;
    long long target = 100;
    int count = 0;
    while (target < X) {
        target += target / 100;
        count++;
    }
    cout << count << endl;
    return 0;
}