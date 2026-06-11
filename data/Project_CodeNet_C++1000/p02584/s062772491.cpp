#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;


long long X, K, D;

void read() {
    cin >> X >> K >> D;
}


void work() {
    if (K > llabs(X) / D) {
        if ((K - llabs(X) / D) % 2 == 0) {
            cout << llabs(X) % D << endl;
        } else {
            cout << D - llabs(X) % D << endl;
        }
    } else {
        cout << llabs(X) - K * D << endl;
    }
}


int main() {
    read();
    work();
    return 0;
}
