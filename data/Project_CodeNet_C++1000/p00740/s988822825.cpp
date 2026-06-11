#include <iostream>
using namespace std;

int main() {
    while (true) {
        int n, p;
        cin >> n >> p;
        if ((n | p) == 0) {
            break;
        }
        int stone = p, player = 0, win = 0;
        int* players = new int [n];
        for (int i = 0; i < n; i++) {
            players[i] = 0;
        }
        while (true) {
            if (stone > 0) {
                players[player]++;
                stone--;
                if (stone == 0) {
                    bool winFlag = true;
                    for (int i = 0; i < n; i++) {
                        if (i != player && players[i] > 0) {
                            winFlag = false;
                            break;
                        }
                    }
                    if (winFlag) {
                        win = player;
                        break;
                    }
                }
            } else {
                stone += players[player];
                players[player] = 0;
            }
            if (player < n - 1) {
                player++;
            } else {
                player = 0;
            }
        }
        cout << win << endl;
        delete[] players;
    }
}