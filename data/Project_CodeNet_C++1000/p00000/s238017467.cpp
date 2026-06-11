#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

string expr(int x, int y) {
    stringstream ss;
    ss << x << "x" << y << "=" << x*y;
    return ss.str();
}

int main() {
    set<string> c;
    int n = 1e5;
    while (n--) {
        int x = rand() % 9 + 1;
        int y = rand() % 9 + 1;
        c.insert(expr(x, y));
    }
    for (set<string>::iterator it=c.begin(); it!=c.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}