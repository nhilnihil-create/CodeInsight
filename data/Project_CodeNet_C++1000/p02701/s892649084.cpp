#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip>

#define PI 3.14159265358979323846
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }

    set<string> count;
    for (int i = 0; i < n; i++) {
        count.insert(s.at(i));
    }

    cout << count.size() << endl;
}