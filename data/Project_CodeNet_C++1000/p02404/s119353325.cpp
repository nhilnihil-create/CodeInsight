#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
//
// Created by karayuu on 2018-12-24.
//

int main() {
    int h, w;
    while (true) {
        cin >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        string s;
        for (int i = 1; i <= w; i++) {
            s += "#";
        }
        cout << s << endl;

        for (int i = 1; i <= h - 2; i++) {
            string _s;
            _s += "#";
            for (int j = 1; j <= w - 2; j++) {
                _s += ".";
            }
            _s += "#";
            cout << _s << endl;
        }

        cout << s << endl;
        cout << endl;
    }
}
