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
        stringstream ss;
        while (w) {
            ss << '#';
            --w;
        }
        string str = ss.str();
        while (h) {
            cout << str << endl;
            --h;
        }
        cout << endl;
    }
    return 0;
}