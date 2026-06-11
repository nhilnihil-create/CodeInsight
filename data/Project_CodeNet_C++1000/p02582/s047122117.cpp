#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    if (s[0] == 'S') {
        if (s[1] == 'S') {
            if (s[2] == 'S') cout << 0;
            else cout << 1;
        } else {
            if (s[2] == 'S') cout << 1;
            else cout << 2;
        }
    } else {
        if (s[1] == 'S') {
            if (s[2] == 'S') cout << 1;
            else cout << 1;
        } else {
            if (s[2] == 'S') cout << 2;
            else cout << 3;
        }
    }
}
