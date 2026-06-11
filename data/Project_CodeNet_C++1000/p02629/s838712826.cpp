#include <iostream>
#include <string>

using namespace std;

int main() {
    long long n;    cin >> n;
    string s;
    while (n > 0) {
        s.push_back('a'+(n-1)%26);
        n = (n-1) / 26;
    }
    for (int i = s.length()-1; i >= 0; i--)
        cout << s[i];
    cout << endl;
    return 0;
}