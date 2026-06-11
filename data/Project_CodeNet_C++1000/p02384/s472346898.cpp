#include <iostream>
#include <string>
using namespace std;

class Dice {
public:
    int face[6];
    Dice() {}
    void dir(char ch) {
        if (ch == 'E') rot(0, 2, 5, 3);
        if (ch == 'W') rot(0, 3, 5, 2);
        if (ch == 'S') rot(0, 1, 5, 4);
        if (ch == 'N') rot(0, 4, 5, 1);
    }
    void rot(int a, int b, int c, int d) {
        int t[4] = {};
        t[0] = face[a];
        t[1] = face[b];
        t[2] = face[c];
        t[3] = face[d];
        face[a] = t[3];
        face[b] = t[0];
        face[c] = t[1];
        face[d] = t[2];
    }
    int side(int f) {
        if (f == 0 || f == 1 || f == 5) { return 0; }
        if (f == 3) rot(1, 2, 4, 3);
        if (f == 2) {
            for (int i = 0; i < 3; i++) {
                rot(1, 2, 4, 3);
            }
        }
        if (f == 4) {
            for (int i = 0; i < 2; i++) {
                rot(1, 2, 4, 3);
            }
        }
    }
};
int main() {
    Dice dice1;
    int n, top, front,tnum=0,fnum = 0;
    for (int i = 0; i < 6; i++) {
        cin >> dice1.face[i];
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> top >> front;
        for (tnum = 0; tnum < 6; tnum++) {
            if (dice1.face[tnum] == top) break;
        }
        switch (tnum) {
        case 0:break;
        case 1:
            dice1.dir('N');
            break;
        case 4:
            dice1.dir('S');
            break;
        case 5:
            dice1.dir('N');
            dice1.dir('N');
            break;
        case 2:
            dice1.dir('W');
            break;
        case 3:
            dice1.dir('E');
            break;
        default: break;
        }
        for (fnum = 0; fnum < 6; fnum++) {
            if (dice1.face[fnum] == front) break;
        }
        dice1.side(fnum);
        cout << dice1.face[2] << endl;
    }
    return 0;
}