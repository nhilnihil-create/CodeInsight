#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

#define rep1(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, n, m) for (long long i = (long long)(n); i <= (long long)(m); i++)
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    bool result = s.length() % 2 == 0;
    rep1(i, s.length()) {
        result = result && (i % 2 == 0 ? s.at(i) == 'h' : s.at(i) == 'i');
    }
    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}