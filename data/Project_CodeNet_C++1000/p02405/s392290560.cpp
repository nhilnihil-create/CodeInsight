#include<iostream>
using namespace std;

int main() {
        int H[10000], W[10000], i, b, j = 0;

        for (i = 0; i < 10000; i++) {
                cin >> H[i] >> W[i];
                if (H[i] == 0 && W[i] == 0) break;
        }

        for (j; j < i; j++) {
                for (int k = 0; k < H[j]; k++) {
                        for (int l = 0; l < W[j]; l++) {
                                if (k % 2 == 0) {
                                        if (l % 2 == 0) cout << "#";
                                        else cout << ".";
                                }
                                else {
                                        if (l % 2 == 0) cout << ".";
                                        else cout << "#";
                                }
                        }
                        cout << endl;
                }
                cout << endl;
        }
}