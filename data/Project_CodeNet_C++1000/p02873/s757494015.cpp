// 解説AC
// う　し　た　ぷ　に　き　あ　く　ん　笑
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    vector<int> a(s.size() + 1);
    a.at(0) = 0;

    vector<int> leftless(s.size() + 1), rightgreater(s.size() + 1);

    leftless[0] = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<')
            leftless[i + 1] = leftless[i] + 1;
        else
            leftless[i + 1] = 0;
    }

    rightgreater[s.size()] = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '>')
            rightgreater[i] = rightgreater[i + 1] + 1;
        else
            rightgreater[i] = 0;
    }

    for (int i = 0; i < s.size() + 1; i++) {
        a[i] = max(leftless[i], rightgreater[i]);
    }

    int sum_a = 0;
    for (int i = 0; i < s.size() + 1; i++) {
        sum_a += a[i];
    }

    cout << sum_a << endl;
}
