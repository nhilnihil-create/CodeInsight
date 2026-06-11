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
    set<char> odd;
    set<char> even;

    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        if(i % 2 == 0) {
            odd.insert(s[i]);
        } else {
            even.insert(s[i]);
        }
    }

    int is_odd = odd.count('L');   // Lがあれば1
    int is_even = even.count('R'); // Rがあれば1

    if(is_odd || is_even) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}