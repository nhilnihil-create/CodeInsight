#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;

    int years = 0;
    long long deposit = 100;
    do {
        deposit += deposit / 100;
        years++;
    } while (deposit < x);

    cout << years;
}