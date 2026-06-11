#include <bits/stdc++.h>

using namespace std;

char buf[10];

void recurse(int length, int pos, int char_used) {
    if (length == pos) {
        for (int i = 0; i < length; i++) {
            cout << buf[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= char_used + 1; i++) {
        buf[pos] = 'a' + i - 1;
        recurse(length, pos + 1, max(char_used, i));
    }
}

int main() {
    int n;
    cin >> n;
    recurse(n, 0, 0);
    return 0;
}