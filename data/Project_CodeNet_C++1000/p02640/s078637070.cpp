#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using ll = long long;

int bird = 2;
int tatol = 4;

int main() {
    int x, y;
    cin >> x >> y;

    if (y % bird != 0) {
        cout << "No" << endl;
        return 0;
    }
    if (x * bird > y || x * tatol < y) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}