#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
    string str, order, rep;
    int n, s, t;
    cin >> str >> n;
    for (int i = 0; i < n; i++) {
        cin >> order >> s >> t;
        if (order == "replace") {
            cin >> rep;
            str.replace(s,t-s+1, rep);
        } else if (order == "reverse") {
            reverse(str.begin() + s, str.begin() + t + 1);
        } else {
            cout << str.substr(s, t-s+1) << endl;
        }
    }
    return 0;
}