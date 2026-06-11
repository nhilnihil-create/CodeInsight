#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long
using namespace std;

int main() {
    string s;
    string t;
    cin >> s >> t;
    if (s.compare(t.substr(0, t.size() - 1)) == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
