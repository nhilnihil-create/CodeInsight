#include <iostream>
using namespace std;

int main() {
    long long n,k;
    cin >> n >> k;
    long long cnt=0;
    while (n > 0) {
        cnt++;
        n /= k;
    }
    cout << cnt;
}