#include <iostream>

using namespace std;

int main() {
    long long a, b;
    string s;
    cin >> a >> s;
    b = (s[0]-'0')*100;
    if (s.length() > 2)
        b += (s[2]-'0')*10;
    if (s.length() > 3)
        b += (s[3]-'0');
    cout << a * b / 100 << endl;

    return 0;
}