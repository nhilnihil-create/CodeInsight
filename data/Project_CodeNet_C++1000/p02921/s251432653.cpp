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
    string s, t;
    cin >> s >> t;

    int count = 0;

    rep(i, s.length()) {
        if(s[i] == t[i])
            count++;
    }
    cout << count << endl;
}
