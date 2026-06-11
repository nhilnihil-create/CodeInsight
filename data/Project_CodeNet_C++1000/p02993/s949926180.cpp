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

    string ans = "Good";
    rep(i, 3) {
        if(s[i] == s[i + 1]) {
            ans = "Bad";
        }
    }
    cout << ans << endl;
}