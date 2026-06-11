#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;
    if (k < s.size()) {
        for (int i = 0; i < k; i++) {
            cout << s.at(i);
        }
        cout << "..." << endl;
    }
    else {
        for (int i = 0; i < s.size(); i++) {
            cout << s.at(i);
        }
    }
}