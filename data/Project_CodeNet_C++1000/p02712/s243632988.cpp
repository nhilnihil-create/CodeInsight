#include <iostream>
using namespace std;
int main() {
    int n = 0;
    long long int sum =0;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        if(not(i % 3 == 0 || i % 5 == 0)) {
            sum = i+sum;
        }
    }
    cout << sum;
    return 0;
}
