#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int H, W;
    while (cin >> H >> W, H) {
        for (int i=0; i<H; ++i) {
            for (int j=0; j<W; ++j) {
                if (i % (H-1) == 0 || j % (W-1) == 0) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}