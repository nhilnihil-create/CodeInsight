#include<iostream>
using namespace std;

int main() {
        int H[10000], W[10000], i, a, k;
        i = 100000;
        a = 0;
        for (k; k < i; k++) {
                cin >> H[k] >> W[k];
                if (H[k] == 0 && W[k] == 0) break;
        }
        for (a; a < k; a++) {
                for (int l = 0; l < W[a]; l++) cout << "#";
                cout << endl;
                for (int m = 0; m < H[a] - 2; m++) {
                        cout << "#";
                        for (int n = 0; n < W[a] - 2; n++) cout << ".";
                        cout << "#" << endl;
                }
                for (int l = 0; l < W[a]; l++) cout << "#";
                cout << endl << endl;
        }
}