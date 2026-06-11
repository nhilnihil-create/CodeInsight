#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

unsigned long long n;
string s;

int main() {
    cin >> n;
    while(n) {
        n--;
        char c = n%26 + 'a';
        n /= 26;
        s.push_back(c);
    }
    reverse(s.begin(), s.end());
    cout << s;
}
