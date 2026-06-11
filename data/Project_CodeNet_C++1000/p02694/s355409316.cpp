#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;

int main(void) {
    ll X;
    cin >> X;

    ll dep = 100;

    int yr = 0;
    while (dep < X)
    {
        dep += dep / 100;
        yr++;
    }
    
    cout << yr << endl;

    return 0;
}
