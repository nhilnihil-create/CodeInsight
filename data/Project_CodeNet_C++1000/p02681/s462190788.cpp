#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define PI 3.14159265358979323846
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int u = s.size();
    string v = t.substr(0, u);
    if (t.size() == u + 1 && s == v) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}