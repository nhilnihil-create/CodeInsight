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
    int n;
    cin >> n;
    string s;
    cin >> s;

    rep(i, s.length()) {
        s[i] += n;
        if(s[i] > 'Z') {
            s[i] -= 26;
        }
    }

    cout << s << endl;
}