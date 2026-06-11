#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 246912;

int prime[MAX_N];
bool is_prime[MAX_N + 1];

int sieve(int n) {
    int p = 0;
    for(int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            prime[p] = i;
            p++;
            for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return p;
}

int main(void) {
    int n;
    while(1){
        cin >> n;
        if(!n) break;
        cout << sieve(2*n) - sieve(n) << endl;
    }

    return 0;
}