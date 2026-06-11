#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

#define ll long long
#define el '\n'
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define VI vector<int>
#define VII vector<pair<int, int>>
#define PII pair<int, int>
#define MP make_pair
// #define log(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define log(fmt, ...)
// #define check(...) assert(##__VA_ARGS__)
#define check(...)

int n;

void dfs(int index, string s, int max_till_now) {
    if (index > n) {
        cout << s << el;
        return;
    }
    rep(i, 'a', max_till_now + 1) {
        s.push_back(i);
        dfs(index + 1, s, max(i, max_till_now));
        s.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string s = "a";
    dfs(2, s, 'a');
}
