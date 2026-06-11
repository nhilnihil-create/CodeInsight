#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int c = 0;
    int max_c = 0;
    for(int i = 0; i < (int)s.length(); i++) {
        if(s[i] == 'R') {
            c++;
            if(c > max_c) {
                max_c = c;
            }
        } else {
            c = 0;
        }
    }

    cout << max_c << endl;
}
