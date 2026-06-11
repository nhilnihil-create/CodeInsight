#include <bits/stdc++.h>
using namespace std;
























bool isprime (int a) {
    for (int i = 2; i * i  <= a; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}



int main () {
    int x;
    cin >> x;

    for (int i = x; ; i++) {
        if (isprime(i)) {
            cout << i << endl;
            break;
        }
    }
}