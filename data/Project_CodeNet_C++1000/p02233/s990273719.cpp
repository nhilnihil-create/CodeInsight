#include <iostream>
using namespace std;

int F[50];

int main() {

    int n;
    cin >> n;
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i < 45; i++) {
        F[i] = F[i-1] + F[i-2];
    }
    cout << F[n] << '\n';
}

