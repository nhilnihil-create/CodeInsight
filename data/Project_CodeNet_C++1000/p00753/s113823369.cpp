#include<iostream>
#include<set>

using namespace std;

set<int> primes;

int main() {
    int n;

    for (int n=2; n<=123456*2; n++) {
        bool is_prime = true;
        for (set<int>::iterator iter=primes.begin(); iter!=primes.end(); iter++) {
            if ((*iter)*(*iter) > n) {
                break;
            }
            if (n%(*iter) == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primes.insert(n);
        }
    }
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        int count = 0;
        for (int i=n+1; i<=2*n; i++) {
            if (primes.find(i) != primes.end()) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}