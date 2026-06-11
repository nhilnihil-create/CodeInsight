#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <locale>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

string solve(string s) {
    // queue<int> stack;
    stack<int> stack;
    bool flag = true;
    int check;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(')
            stack.push(1);
        else if (s[i] == '[')
            stack.push(2);
        if (s[i] == ')') {
            if (stack.empty()) return "no";
            check = stack.top();
            stack.pop();
            if (check != 1) {
                return "no";
            }
        } else if (s[i] == ']') {
            if (stack.empty()) return "no";
            check = stack.top();
            stack.pop();
            if (check != 2) {
                return "no";
            }
        }
    }
    // if (!stack.empty()) flag = false;
    // if (flag) return "yes";
    // return "no";
    return stack.empty() ? "yes" : "no";
}

int main() {
    string st;
    vector<string> ans;
    while (1) {
        // cout << 1;
        getline(cin, st);
        // cout << 2;
        if (st == ".") break;
        // cout << 3;
        // cout << st << endl;
        ans.push_back(solve(st));
        // cout << 4;
    }
    for (auto k : ans) cout << k << endl;
}
