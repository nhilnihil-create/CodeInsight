#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
//
// Created by karayuu on 2018-12-24.
//

int main() {
    while (true) {
        int h, w;
        cin >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        for (int i = 1; i <= h; i++) {
            string s;
            if (i % 2 == 1) {
                //奇数行
                for (int j = 1; j <= w; j++) {
                    if (j % 2 == 1) {
                        //奇数行の奇数番目
                        s += '#';
                    } else {
                        //奇数行の偶数番目
                        s += ".";
                    }
                }
            } else {
                //偶数行
                for (int j = 1; j <= w; j++) {
                    if (j % 2 == 1) {
                        //偶数行の奇数番目
                        s += ".";
                    } else {
                        //偶数行の偶数番目
                        s += "#";
                    }
                }
            }
            cout << s << endl;
        }
        cout << endl;
    }
}
