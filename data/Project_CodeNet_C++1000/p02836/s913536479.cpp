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

    int ans = 0;
    int length = s.length();
    rep(i, length / 2) {
        if(s[i] != s[length - 1 - i]) {
            ans++;
        }
    }

    cout << ans << endl;
}