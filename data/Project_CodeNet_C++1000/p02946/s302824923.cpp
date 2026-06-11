#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int K, X; cin >> K >> X;
    int tmp = (X - K) + 1;
    for (int i = 0; i < (K - 1) * 2 + 1; ++i) {
        cout << tmp << " ";
        tmp++;
    }
    cout << endl;
}
