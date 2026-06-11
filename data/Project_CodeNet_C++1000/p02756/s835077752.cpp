#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, head, tail;
    cin >> s;

    int q;
    scanf("%d", &q);

    int mode = 0;

    while (q--) {
        int t;
        scanf("%d", &t);

        if (t == 1) {
            mode ^= 1;
        }
        else {
            int x;
            char c;
            scanf("%d%c%c", &x, &c, &c);

            x--;

            if (x ^ mode == 0) head += c;
            else tail += c;
        }
    }

    if (mode == 0) {
        reverse(head.begin(), head.end());
        cout << head << s << tail << endl;
    }
    else {
        reverse(tail.begin(), tail.end());
        reverse(s.begin(), s.end());
        cout << tail << s << head << endl;
    }
}
