#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

bool is_palindrome(std::string s){
    std::string t = s;
    std::reverse(t.begin(), t.end());
    return s == t;
}

int main(){
    std::string s;
    std::cin >> s;

    int n = s.size();
    if (is_palindrome(s) && is_palindrome(s.substr(0, (n - 1) / 2)) && is_palindrome(s.substr((n + 1) / 2)))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}