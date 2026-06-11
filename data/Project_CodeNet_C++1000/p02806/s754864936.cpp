#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

int main() {
    int N;
    cin >> N;
    vector<pair<string, int>> V;
    for (int i = 0; i < N; i++) {
        string s;
        int tm;
        cin >> s >> tm;
        V.push_back(make_pair(s, tm));
    }
    string X;
    cin >> X;
    bool OK = false;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (V[i].first == X) {
            OK = true;
            continue;
        }
        if (!OK) continue;
        ans += V[i].second;
    }
    printf("%d\n", ans);
    return 0;
}
