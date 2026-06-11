#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    while(1) {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        } else {
            for (int j = 0; j < w; j++) {
                cout << "#";
            }
            cout << endl;
            for (int i = 1; i < h - 1; i++) {
                cout << "#";
                for (int j = 1; j < w - 1; j++) {
                    cout << ".";
                }
                cout << "#" << endl;
            }
            for (int j = 0; j < w; j++) {
                cout << "#";
            }
            cout << endl << endl;
        }
    }
    return 0;
}
