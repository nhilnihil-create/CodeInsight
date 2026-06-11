#include <iostream>
#include <string>

int main(){
    std::string s, t;
    std::cin >> s >> t;
    int count = 0;

    if (s[0] == t[0])
    {
        count++;
    }
    if (s[1] == t[1])
    {
        count++;
    }
    if (s[2] == t[2])
    {
        count++;
    }

    std::cout << count << std::endl;

    return 0;
}