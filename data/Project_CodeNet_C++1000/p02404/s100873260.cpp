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
        for (int i = 0; i < w; ++i) {
            ss1 << '#';
            ss2 << (!i || i == w - 1 ? '#' : '.');
        }
        string str1 = ss1.str(), str2 = ss2.str();
        for (int j = 0; j < h; ++j) {
            cout << (!j || j == h - 1 ? str1 : str2) << endl;
        }
        cout << endl;
    }
    return 0;
}