#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
bool prime[N];

void sieve() {
    memset(prime , 1 , sizeof prime);
    prime[0] = prime[1] = 0;
    for (int i = 2 ;i * i < N ;i++)
        if (prime[i])
            for (int j = i * i ;j < N ;j += i)
                prime[j] = 0;
}

int main() {
    sieve();
    int n;
    cin >> n;

    for (int i = n ; ;i++) {
        if (prime[i]) {
            cout << i;
            return 0;
        }
    }
}
