#include <iostream>
#include <string>
using namespace std;

int loopCount(const int button, const int count) {
    if (button == 1) {
        return (count - 1) % 5;
    } else if (button == 7 || button == 9) {
        return (count - 1) % 4;
    }
    return (count - 1) % 3;
}

int main() {
    const char keitaiChar[][6] = {".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        int preButton = 0, count = 0;
        for (string::iterator it = input.begin(); it < input.end(); it++) {
            int button = *it - '0';
            if (button == 0) {
                if (preButton != 0) {
                    cout << keitaiChar[preButton - 1][loopCount(preButton, count)];
                    count = 0;
                }
            } else {
                count++;
            }
            preButton = button;
        }
        cout << endl;
    }
}