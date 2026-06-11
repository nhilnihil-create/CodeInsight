#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++) {
        s.at(i) = s.at(i) + n;
        if (s.at(i) > 'Z') {
            s.at(i) = s.at(i) - 26;
        }
    }
    cout << s << endl;
}