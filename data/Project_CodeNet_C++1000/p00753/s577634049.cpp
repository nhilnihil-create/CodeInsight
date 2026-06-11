#include<iostream>

using namespace std;
const int n = 123456 * 2 + 1;
bool sieve[n] = {false};
int cnt[n] = {0};

int main() {
    for (int i = 2; i < n; ++i) {
        if (!sieve[i])
            for (int k = i + i; k < n; k += i) sieve[k] = true;
    }

    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (!sieve[i]) c++;
        cnt[i] = c;
        //cout << c << " ";
    }

    while (1) {
        int i;
        cin >> i;
        if (i == 0) break;

        cout << cnt[i * 2] - cnt[i] << endl;
    }
}