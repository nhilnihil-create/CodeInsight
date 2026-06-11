#include <iostream>
#include <vector> 
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

#define int long long

signed main() { 
    int h, w;
    cin >> h >> w;
    if(h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }

    if((h * w) % 2 == 0) {
        cout << h * w / 2 << endl;
        return 0;
    }

    cout << h * w / 2 + 1 << endl;
    return 0;
}