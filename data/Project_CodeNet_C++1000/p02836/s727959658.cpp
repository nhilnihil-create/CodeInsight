#include<iostream>
#include<vector>
#include<string>

int main () {
    std::string s;
    std::cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i]) {
            ans++;
        }
    }

    std::cout << ans << "\n";
}