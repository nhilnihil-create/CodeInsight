#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(void) {
    string S;
    cin >> S;

    int sum = 0;
    for (auto c: S) {
        sum += c - 48;
    }

    cout << (sum % 9 ? "No":"Yes") << endl;
    
    return 0;
}