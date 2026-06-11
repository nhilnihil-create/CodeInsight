#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; 
    string s;
    cin >> n >> s;
    for (size_t i = 0, sz = s.size(); i < sz; ++i) {
        int a = (s[i] - 'A' + n) % 26;

        s[i] = a + 'A';
    }

    cout << s << "\n";
}