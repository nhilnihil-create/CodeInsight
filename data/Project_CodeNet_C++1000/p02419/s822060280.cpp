#include <iostream>
using namespace std;

int get_index(char c) {
    if (0x41 <= c && c <= 0x5a) {
        return int(c) - 0x41;
    }
    if (0x61 <= c && c <= 0x7a) {
        return int(c) - 0x61;
    }
    return 26;
}

int compare(string &a, string &b) {
    if (a.length() != b.length()) return 0;

    for (int i = 0; i < a.length(); ++i) {
        if (get_index(a[i]) != get_index(b[i])) {
            return 0;
        } else {
            continue;
        }
    }

    return 1;
}

int main() {
    string W;
    cin >> W;

    int count;
    for (;;) {
        string T;
        cin >> T;

        if (T == "END_OF_TEXT") break;

            if (compare(W, T)) ++count;
    }
    cout << count << endl;

    return 0;
}