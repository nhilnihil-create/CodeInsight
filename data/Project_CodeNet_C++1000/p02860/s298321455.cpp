#include <iostream>
using namespace std;

bool check(int n, string s) {
    if (s.length() != n) {
        return false;
    }
    string t = s.substr(0, n / 2);
    if (t + t != s) {
        return false;
    }
    return true;
}
int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    if (check(n, s)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
