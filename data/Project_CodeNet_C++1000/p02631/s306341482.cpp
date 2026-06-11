#include<iostream>
using namespace std;
const int BUF = 200005;


int nVal;
int val[BUF];

void read() {
    cin >> nVal;
    for (int i = 0; i < nVal; ++i) {
        cin >> val[i];
    }
}


void work() {
    int bit2cnt[31] = {};

    for (int i = 0; i < nVal; ++i) {
        for (int bit = 0; bit < 31; ++bit) {
            if (val[i] & (1 << bit)) {
                ++bit2cnt[bit];
            }
        }
    }

    int ans[BUF] = {};
    for (int i = 0; i < nVal; ++i) {
        for (int bit = 0; bit < 31; ++bit) {
            int isOn = (val[i] & (1 << bit)) > 0;
            if (bit2cnt[bit] % 2 == 0) {
                ans[i] |= isOn << bit;
            } else {
                ans[i] |= (!isOn) << bit;
            }
        }
    }

    for (int i = 0; i < nVal; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}


int main() {
    read();
    work();
    return 0;
}
