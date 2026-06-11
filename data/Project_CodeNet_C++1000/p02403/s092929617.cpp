#include<iostream>
#include<stdio.h>
#include<cmath>
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
            for (int j = 1; j <= w; j++) {
                s += "#";
            }
            cout << s << endl;
        }
        cout << endl;
    }
}
