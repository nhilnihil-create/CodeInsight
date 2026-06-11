#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>
#include<functional>

using namespace std;
typedef long long ll;

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    int n;
    cin >> n;
    map<string, int> ans;
    int count = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ans[s]++;
        count = max(count, ans[s]);
    }
    for (auto x : ans) {
        if (x.second == count) cout << x.first << endl;
    }
}
