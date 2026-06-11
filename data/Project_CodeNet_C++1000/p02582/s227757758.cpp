#include <bits/stdc++.h>

using namespace std;

int main () {

    string str;
    int result;
    cin >> str;

    if (str[0] == 'R') {
        result = 1;
    } else {
        result = 0;
    }

    if (str[1] == 'R') {
        if (str[2] == 'R') {
            result += 2;
        } else {
            result += 1;
        }
    }

    if (result == 0 && str[2] == 'R') {
        result = 1;
    }
    
    cout << result << endl;

    return 0;
}
