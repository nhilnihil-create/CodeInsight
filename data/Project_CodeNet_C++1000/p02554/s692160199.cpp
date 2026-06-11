#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    long long int mod = 1000000000 + 7;
    long long int result = 1;
    long long int result1 = 1;
    long long int result2 = 1;
    for (int i = 0; i < N; i++) {
        result *= 10;
        result = result % mod;
        result1 *= 9;
        result1 = result1 % mod;
        result2 *= 8;
        result2 = result2 % mod;
    }

    result = (result - 2 * result1 + result2) % mod;
    
    if (result < 0) {
        result += mod;
    }

    if (result < 0) {
        result += mod;
    }

    cout << result << endl;

    return 0;
}