#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

int main() {
    uint64_t a; cin >> a;
    string b; cin >> b;

    cout << (a * ((b[0] - '0') * 100 + (b[2] - '0') * 10 + (b[3] - '0') * 1) / 100) << endl;
}

