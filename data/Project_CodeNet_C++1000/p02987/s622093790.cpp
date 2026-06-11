#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<map>
#include<deque>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define erep(i, n) for (int i = 0; i <= (int)(n); i++)

int main() {
    string s; cin >> s;
    map<char, int> m;
    rep (i, 4) m[s[i]]++;
    bool flag = true;
    for (auto v : m) {
        if (v.second != 2) flag = false;
    }
    cout << (flag ? "Yes" : "No") << endl;
}
