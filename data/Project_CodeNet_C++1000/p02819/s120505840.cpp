
#include <bits/stdc++.h>

using namespace std;

typedef long int lint;
typedef long long int llint;

#define INF 1073741824
#define LINF 4611686018000000000
#define MOD 1000000007

int prime(int x) {
    if (x == 2) return 2;
    if (x % 2 == 0) x++;
    bool ok = false;
    while (!ok) {
        ok = true;
        for (int i = 3; i * i <= x; i+=2) {
            if (x % i == 0) {
                ok = false;
                break;
            }
        }
        if (!ok) x+=2;
    }
    return x;
}

int main() {
    int x;
    cin >> x;
    cout << prime(x) << endl;
    return 0;
}
