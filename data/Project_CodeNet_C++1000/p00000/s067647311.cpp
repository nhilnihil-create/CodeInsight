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
    for (int i=1e3; i; --i) {
        c.insert(expr(rand() % 9 + 1, rand() % 9 + 1));
    }
    for (auto it=c.begin(); it!=c.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}