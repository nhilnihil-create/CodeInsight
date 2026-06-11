#include <iostream>
#include <string>
#include <vector>

#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)

using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;

    int n;
    cin >> n;
    while (n--) {
        int input;
        cin >> input;
        if (input % 2 == 0) {
            if (input % 3 != 0 && input % 5 != 0) {
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}