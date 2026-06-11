#include <iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
using namespace std;
using lli = long long int;

int main() {
    int x;
    cin >> x;
    int m = 100010;
    vector<bool> p(m, true);
    p[0] = p[1] = false;
    for (int i = 2; i < (int)sqrt(m); i++) {
        if (p[i] == false) {
            continue;
        }
        for (int j = i * 2; j < m; j += i) {
            p[j] = false;
        }
    }
    for (int i = x; i < m; i++) {
        if (p[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}