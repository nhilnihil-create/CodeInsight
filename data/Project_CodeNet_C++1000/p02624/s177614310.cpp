#include<iostream>
#include<numeric>
using namespace std;
const int PRIME = 10000;
const int BUF = 10000001;


int nPrime, prime[PRIME];

void makePrime() {
    bool isPrime[PRIME];
    for (int i = 0; i < PRIME; ++i) isPrime[i] = true;
    for (int i = 2; i * i <= PRIME; ++i)
        if (isPrime[i])
            for (int j = i * 2; j < PRIME; j += i)
                isPrime[j] = false;
    nPrime = 0;
    for (int i = 2; i < PRIME; ++i)
        if (isPrime[i])
            prime[nPrime++] = i;
}

long long table[BUF];

int calcNumDivisor(int n) {
    int ret = 1;
    for (int i = 0; prime[i] * prime[i] <= n; ++i) {
        if (n % prime[i] == 0) {
            int cnt = 0;
            while (n % prime[i] == 0) {
                ++cnt;
                n /= prime[i];
            }
            ret *= cnt + 1;
        }
    }
    if (n > 1) ret *= 2;
    return ret;
}

void makeTable() {
    for (int i = 1; i < BUF; ++i)
        table[i] = 1LL * i * calcNumDivisor(i);
}

int N;

void read() {
    cin >> N;
}


void work() {
    cout << accumulate(table + 1, table + N + 1, 0LL) << endl;
}


int main() {
    makePrime();
    makeTable();
    read();
    work();
    return 0;
}
