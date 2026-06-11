#include <iostream>
#include <string>
using namespace std;

int main() {
    int k; cin >> k;
    string s; cin >> s;

    cout << s.substr(0, k) << (k < s.size() ? "..." : "") << endl;
}

