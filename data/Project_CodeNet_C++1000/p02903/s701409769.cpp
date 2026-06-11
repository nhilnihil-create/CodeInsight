#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            cout << "0";
        }
        for (int j = 0; j < w - a; j++) {
            cout << "1";
        }
        cout << endl;
    }
    for (int i = 0; i < h - b; i++) {
        for (int j = 0; j < a; j++) {
            cout << "1";
        }
        for (int j = 0; j < w - a; j++) {
            cout << "0";
        }
        cout << endl;
    }
    return 0;
}