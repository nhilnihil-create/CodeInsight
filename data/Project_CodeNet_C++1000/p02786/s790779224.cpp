#include <iostream>
using namespace std;

long long battle(long long HP) {
    if (HP == 1) return 1;
    else return battle(HP/2) * 2 + 1;
}

int main() {
    long long HP;
    cin >> HP;
    cout << battle(HP) << endl;
}