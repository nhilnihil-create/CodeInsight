#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
int main() {
    string s;
    int K;
    cin >> s;
    set<char>st;
    for (auto i : s)st.insert(i);
    cin >> K;
    if (st.size() == 1) {
        cout << (K*s.size()) / 2 << endl;
        return 0;
    }
    long long int a = 0;
    auto t = s;
    for (int i = 1; i < t.size(); i++) {
        if (t[i] == t[i - 1]) {
            a++;
            t[i] = '#';
        }
    }
    s += s;
    long long int b = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            b++;
            s[i] = '#';
        }
    }
    b -= a;
    cout << (K-1) * b + a << endl;
    return 0;
}
