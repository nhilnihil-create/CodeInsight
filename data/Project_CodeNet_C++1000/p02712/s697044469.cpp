#include <iostream>
#include <memory>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    int n;
    cin >> n;

    int idx = 1;
    llint sum = 0;
    while (true) {
        if (idx % 15 != 0 && idx % 3 != 0 && idx % 5 != 0) {
            sum += idx;
        }
        if (idx == n)
            break;
        idx++;
    }
    cout << sum << endl;
}

