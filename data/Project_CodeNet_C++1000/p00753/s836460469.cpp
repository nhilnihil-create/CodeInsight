#include <iostream>
#include <vector>
#define MAX_N (123456 * 2 + 1)

using namespace std;

int main() {
    bool isPrime[MAX_N];
    fill_n((bool *)isPrime, MAX_N, true);
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i < MAX_N; i++) {
        for (int j = i+i; j < MAX_N; j += i) {
            isPrime[j] = false;
        }
    }
    
    int n;
    while (cin >> n, n) {
        int count = 0;
        for (int i = n+1; i <= n*2; i++) {
            if (isPrime[i]) count++;
        }
        cout << count << endl;
    }

    return 0;
}