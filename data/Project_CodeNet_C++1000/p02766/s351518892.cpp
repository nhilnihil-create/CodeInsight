#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int i = 1;
    int p = n;
    while (p >= k) {
        p /= k;
        i++;
    }
    cout << i << endl;
}