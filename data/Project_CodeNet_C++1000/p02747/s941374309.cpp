#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    string s;
    cin >> s;
    if (s.size() % 2 != 0) {
        cout << "No\n";
        return 0;
    }
    rep(i,s.size()) {
        if (i % 2 == 0) {
            if (s[i] != 'h') {
                cout << "No\n";
                return 0;
            }
        } else {
            if (s[i] != 'i') {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}