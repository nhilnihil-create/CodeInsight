#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    vector<int> bon = {3};
    vector<int> pon = {0, 1, 6, 8};
    int N;
    cin >> N;
    N %= 10;
    auto check = [&](vector<int> x) {
        if (count(x.begin(), x.end(), N)) return true;
        return false;
    };
    if (check(bon)) puts("bon");
    else if (check(pon)) puts("pon");
    else puts("hon");
    return 0;
}