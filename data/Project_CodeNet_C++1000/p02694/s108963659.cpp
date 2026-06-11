#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long x;
    cin >> x;
    long long p = 100, step = 0;
    while(p < x) {
        p += p / 100;
        step++;
    }
    cout << step << "\n";
    return 0;

}
