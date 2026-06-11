#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
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

int chnum(char c) {
    if (c == 'm')
        return 1000;
    else if (c == 'c')
        return 100;
    else if (c == 'x')
        return 10;
    else if (c == 'i')
        return 1;
    else
        return 0;
}

string intToMcxi(int x) {
    string mcxi;
    char tmp[] = {'i', 'x', 'c', 'm'};
    for (int j = 4; j > 0; j--) {
        int div = 1;
        for (int k = 1; k < j; k++) {
            div *= 10;
        }
        int num = x / div;
        if (num > 0) {
            if (num > 1) mcxi += to_string(num);
            mcxi += tmp[j - 1];
        }
        x -= num * div;
    }
    return mcxi;
}

int mcxiToInt(string mcxi) {
    int ret = 0;
    for (int j = 0; j < mcxi.size(); j++) {
        int a = chnum(mcxi[j]);
        int b = 1;
        if (j > 0 && '0' <= mcxi[j - 1] && '9' >= mcxi[j - 1]) b = (int)(mcxi[j - 1] - '0');
        ret += a * b;
    }
    return ret;
}

string solve(string num1, string num2) {
    int v1     = mcxiToInt(num1);
    int v2     = mcxiToInt(num2);
    string ret = intToMcxi(v1 + v2);
    return ret;
}

int main() {
    int n;
    cin >> n;
    string num1, num2;
    // char c[4] = {m, c, x, i};
    // int v[4] = {1000, 100, 10, 1};

    vector<string> ans;

    for (int i = 0; i < n; i++) {
        cin >> num1 >> num2;
        ans.push_back(solve(num1, num2));
    }

    for (string s : ans) cout << s << endl;
}
