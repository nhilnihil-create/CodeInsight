#include<iostream>
using namespace std;

int main() {
        int H[10000], W[10000], i, a, k;
        i = 100000;
        a = 0;
        k = 0;
        for (k; k < i; k++) {
                cin >> H[k] >> W[k];
                if (H[k] == 0 && W[k] == 0) break;
        }
        for (int j = 0; j < k; j++) {
                for (int l = 1; l < H[j] + 1; l++) {
                        for (int m = 1; m < W[j] + 1; m++) {
                                cout << "#";
                        }
                        cout << endl;
                }
                cout << endl;
        }

}