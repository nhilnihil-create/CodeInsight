#include <iostream>
#include <string>
using namespace std;
int main() {
    string youbi[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    string s;
    cin >> s;
    int i = 0;
    while (youbi[i] != s) {
        i++;
    }
    cout << 7 - i << endl;
}