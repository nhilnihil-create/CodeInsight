#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    string array[10] = {
        "pon", "pon", "hon", "bon", "hon",
        "hon", "pon", "hon", "pon", "hon",
    };

    cout << array[n % 10];
}