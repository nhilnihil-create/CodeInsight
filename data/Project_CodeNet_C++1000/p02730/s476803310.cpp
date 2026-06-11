#include<iostream>
#include<string>
using namespace std;

int isPalindrom(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n-i-1]) return 0;
    }
    return 1;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();

    string s1 = s.substr(0, (n - 1) / 2);
    string s2 = s.substr((n + 3) /2 - 1);

    if (isPalindrom(s) && isPalindrom(s1) && isPalindrom(s2)) cout << "Yes" << endl;
    else cout << "No" << endl;

}