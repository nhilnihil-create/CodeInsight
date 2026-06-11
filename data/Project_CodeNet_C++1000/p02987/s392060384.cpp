#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<char> v;
    for (int i=0; i<4; i++) {
        v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    if (count(v.begin(), v.end(), v[0]) == 2 && count(v.begin(), v.end(), v[2]) == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}