#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> str;

    rep(i, s.length()) { str.insert(s[i]); }

    if(str.size() == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}