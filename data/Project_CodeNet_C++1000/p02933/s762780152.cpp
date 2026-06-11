#include <iostream>
#include <string>
using namespace std;

void _139() {
    string s, t;
    cin >> s;
    cin >> t;

    int count = 0;
    for (int i = 0; i < 3; ++i) {
        if (s[i] == t[i])
            count++;
    }
    cout << count << endl;
}

void _138() {
    int a;
    string s;
    cin >> a;
    cin >> s;

    if (a >= 3200)
        cout << s << endl;
    else
        cout << "red" << endl;
}

int main()
{
    _138();
    return 0;
}

