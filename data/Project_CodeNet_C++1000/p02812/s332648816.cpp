#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int ptr = 0;
    while (ptr < n) {
        if (s[ptr++] == 'A') {
            if (s[ptr] == 'B') {
                ptr++;
                if (s[ptr] == 'C') {
                    ans++;
                    ptr++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}