#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    cin >> text;
    for (int i = 0; i < (int)text.size(); i++) {
        if (text[i] == '?') text[i] = 'D';
    }
    cout << text << endl;
    return 0;
}