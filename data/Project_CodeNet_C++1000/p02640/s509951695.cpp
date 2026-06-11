#include <bits/stdc++.h>

using namespace std;

int main() {
    //X:鶴亀個体数　Y:足の数
    int X, Y, turu;
    bool fg=false;
    cin >> X >> Y;

    for (turu = 0; turu <= X; turu++) {
        if (Y - (turu * 4) - ((X - turu) * 2) == 0) {
            cout << "Yes" << endl;
            fg=true;
        }
    }

    if(!fg)cout << "No" << endl;

}