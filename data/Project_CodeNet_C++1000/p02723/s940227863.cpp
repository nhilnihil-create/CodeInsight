#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;


int main() {
    string s;
    cin >> s;
    if (s.at(2) == s.at(3) && s.at(4) == s.at(5)) {
        cout << "Yes" << endl;
    }
    else {      
        cout << "No" << endl;
    }
}