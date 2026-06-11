#include<iostream>
#include<string>
#include<algorithm>

int main ()  {
    std::string s;
    std::cin >> s;

    std::sort(s.begin(), s.end());

    if(s[0] == s[1] && s[2] == s[3] && s[0] != s[2]) {
        std::cout << "Yes" << "\n";
    } else {
        std::cout << "No" << "\n";
    }

}