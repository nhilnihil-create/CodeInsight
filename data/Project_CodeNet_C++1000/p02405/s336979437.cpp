#include <iostream>
#include <sstream>

using namespace std;


int main() {
    int w, h;

    while (1) {
        cin >> h >> w;
        if (!w && !h) {
            break;
        }
        stringstream ss1, ss2;
        bool b = true;
        while (w) {
            ss1 << (b ? '#' : '.');
            ss2 << (b ? '.' : '#');
            --w;
            b = !b;
        }
        string str1 = ss1.str(), str2 = ss2.str();
        b = true;
        while (h) {
            cout << (b ? str1 : str2) << endl;
            --h;
            b = !b;
        }
        cout << endl;
    }
    return 0;
}