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
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repi(i, a, b) for (int i = a; i >= b; i--)
#define VI vector<int>
#define VII vector<pair<int, int>>
#define PII pair<int, int>
#define MP make_pair
// #define log(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define log(fmt, ...)
// #define check(...) assert(##__VA_ARGS__)
#define check(...)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    int a[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    cout << a[k-1];
}
