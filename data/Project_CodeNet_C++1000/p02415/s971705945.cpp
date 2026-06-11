#include<iostream>
#include<string>

using namespace std;

int main () {

    std::string s;

    getline(cin, s);

    for (int i = 0; i < 1200; i++) {
        if (65 <= s[i] && s[i] <= 90) {
            s[i] += 32;
        } else if (97 <= s[i] && s[i] <= 122) {
            s[i] -= 32;
        }
    }

    cout << s << endl;

    return 0;
}
