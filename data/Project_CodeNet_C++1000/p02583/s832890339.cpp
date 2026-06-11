#include<iostream>
#include<algorithm>
using namespace std;
const int BUF = 105;


int nVal;
int val[BUF];

void read() {
    cin >> nVal;
    for (int i = 0; i < nVal; ++i) {
        cin >> val[i];
    }
}


void work() {
    sort(val, val + nVal);
    
    int cnt = 0;
    for (int i = 0; i < nVal; ++i) {
        for (int j = i + 1; j < nVal; ++j) {
            for (int k = j + 1; k < nVal; ++k) {
                if (val[i] == val[j] || val[i] == val[k] || val[j] == val[k]) continue;
                if (val[i] + val[j] <= val[k]) continue;
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
}


int main() {
    read();
    work();
    return 0;
}
