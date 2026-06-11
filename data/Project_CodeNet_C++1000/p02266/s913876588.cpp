#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

int main() {
    string S;
    cin >> S;
    const int N = S.size();
    stack<int> stk;
    stack<pair<int, int>> pond;
    for (int j = 0; j < N; ++j) {
        if (S[j] == '_') {
            // pass
        } else if (S[j] == '\\') {
            stk.push(j);
        } else if (S[j] == '/' && !stk.empty()) {
            int p = stk.top(); stk.pop();
            int area = j - p;
            while (!pond.empty() && p < pond.top().first) {
                area += pond.top().second;
                pond.pop();
            }
            pond.emplace(p, area);
        }
    }

    int sum_area = 0;
    while (!stk.empty()) stk.pop();
    while (!pond.empty()) {
        int t = pond.top().second;
        sum_area += t;
        stk.push(t);
        pond.pop();
    }

    cout << sum_area << endl;
    cout << stk.size();
    for (; !stk.empty(); stk.pop()) {
        cout << " " << stk.top();
    }
    cout << endl;
    return 0;
}