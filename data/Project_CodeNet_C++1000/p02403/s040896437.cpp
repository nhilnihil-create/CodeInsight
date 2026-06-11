#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main(void) {
    int h,w;
    for (;;){
        cin >> h >> w;
        if (!h && !w) break;
        for (int i=0; i<h; i++) {
            cout << string(w,'#') << endl;
        }
        cout << endl;
    }
    return 0;
}