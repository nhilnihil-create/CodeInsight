#include<iostream>
#include<string>

int main () {
    std::string s;
    std::cin >> s;

    bool ansf = true;

    for (int i = 0; i < s.length(); i++) {
        if(i%2 == 0) {
            if(!(s[i] == 'R' || s[i] == 'U' || s[i] == 'D')) {
                ansf = false;
            }
        } else {
            if (!(s[i] == 'L' || s[i] == 'U' || s[i] == 'D')) {
                ansf = false;
            }
        }
    }

    std::string ans = ansf ? "Yes" : "No";

    std::cout << ans << std::endl;
}