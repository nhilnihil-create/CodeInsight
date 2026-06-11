#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string s, t;

    cin >> s;
    cin >> t;

    int counter = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i])
            counter ++;
    }
    std::cout << counter;

    return 0;
}