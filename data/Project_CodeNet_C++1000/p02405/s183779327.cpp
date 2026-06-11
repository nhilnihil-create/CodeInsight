#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    while(1) {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        } else {
            for (int i = 0; i < h; i++) {
                if (i % 2) {
                    for (int j = 0; j < w / 2; j++) {
                        cout << ".#";
                        
                    }
                    if (w % 2) cout << ".";
                } else {
                    for (int j = 0; j < w / 2; j++) {
                        cout << "#.";
                        
                    }
                    if (w % 2) cout << "#";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}
