#include <iostream>

using namespace std;

int main() {

    while(true) {
        string s;
        cin >> s;
        if (s == "0")
            break;

        int sum = 0;

        for (char& c : s) {
            sum += stoi(string{c});
        }
        cout << sum << endl;
    }
    return 0;
}