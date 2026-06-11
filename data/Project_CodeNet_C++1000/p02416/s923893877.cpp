#include<iostream>

using namespace std;

int main() {

    char s[1000] = {0};

    while (1) {

        cin >> s;

        if(s[0] == '0') {
            break;
        }

        int cnt = 0;

        int i = 0;
        while (1) {
            if ('0' <= s[i] && s[i] <= '9') {
                cnt += s[i] - '0';
            } else {
                break;
            }
            i++;
        }

        cout << cnt << endl;

    }

    return 0;
}
