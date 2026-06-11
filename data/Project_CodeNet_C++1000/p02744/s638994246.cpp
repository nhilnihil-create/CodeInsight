#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
vector<string> ans;
void rec(int n, int num, string str, int mx)
{
    if (n == num) {
        //cout << n << ", " << num << ", " << str << endl;
        ans.push_back(str);
        return;
    }
    rep(i, num + 1) {
        if (num != 0) {
            if (1 < i - mx) break;
        }
        rec(n, num + 1, str + char('a' + i), max(mx, i));
    }
    return;
}
int main()
{
    // パナソニックプログラミングコンテスト2020-D, 1113, 
    int n; cin >> n;
    rec(n, 0, "", 0);
    for (string s : ans) cout << s << endl;
    return 0;
}