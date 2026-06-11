#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool solve(string s) {
    vector<int> v;
    rep (i, s.size()) {
        if (s[i] == '(') v.push_back(1);
        if (s[i] == '[') v.push_back(2);
        if (s[i] == ')') {
            if (v.empty() || v.back() != 1) return false;
            v.pop_back();
        }
        if (s[i] == ']') {
            if (v.empty() || v.back() != 2) return false;
            v.pop_back();
        }
    }
    return v.empty();
}

int main() {
    for (;;) {
        string s;
        while (s.size() == 0 || s[s.size()-1] != '.') {
            string buf;
            getline(cin, buf);
            s += buf;
        }
        if (s == ".") return 0;
        puts(solve(s) ? "yes" : "no");
    }
}