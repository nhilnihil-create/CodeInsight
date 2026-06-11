#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class dice {
    int dice[6];
public:
    void input() {
        for(int i=0; i<6; ++i) cin >> dice[i];
    }
    void output() {
        cout << dice[0];
        for(int i=1; i<6; ++i) cout << ' ' << dice[i];
        cout << endl;
    }
    void move(string state) {
        for(int i=0; i<state.length(); ++i) {
            switch(state[i]) {
                case 'N':
                    swap(dice[0], dice[1]);
                    swap(dice[1], dice[5]);
                    swap(dice[5], dice[4]);
                    break;
                case 'S':
                    swap(dice[0], dice[4]);
                    swap(dice[4], dice[5]);
                    swap(dice[5], dice[1]);
                    break;
                case 'E':
                    swap(dice[0], dice[3]);
                    swap(dice[3], dice[5]);
                    swap(dice[5], dice[2]);
                    break;
                case 'W':
                    swap(dice[0], dice[2]);
                    swap(dice[2], dice[5]);
                    swap(dice[5], dice[3]);
                    break;
                default:
                    break;
            }
        }
    }
    int index_of(int x) {
        for(int i=0; i<6; ++i) {
            if(dice[i] == x) return i;
        }
        return -1;
    }
    int getRightside(int top, int front) {
        int ind;
        ind = index_of(top);
        switch(ind) {
            case 0:
                break;
            case 1:
                move("N");
                break;
            case 2:
                move("W");
                break;
            case 3:
                move("E");
                break;
            case 4:
                move("S");
                break;
            case 5:
                move("NN");
                break;
            default:
                break;
        }
        ind = index_of(front);
        switch(ind) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                move("NWS");
                break;
            case 3:
                move("NES");
                break;
            case 4:
                move("NWWS");
                break;
            case 5:
                break;
            default:
                break;
        }
        return dice[2];
    }
};

int main() {
    dice d;
    d.input();
    int i, n;
    cin >> n;
    int t[n], f[n];

    for(i=0; i<n; ++i) {
        cin >> t[i] >> f[i];
    }
    for(i=0; i<n; ++i) {
        cout << d.getRightside(t[i], f[i]) << endl;
    }

    return 0;
}