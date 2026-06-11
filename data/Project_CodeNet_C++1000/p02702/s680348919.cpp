#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int mul = 1, rem = 0;
    long long answer = 0;
    vector<int> cnt(2222);
    cnt[0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        rem = (rem + (s[i] - '0') * mul) % 2019;
        answer += cnt[rem];
        ++cnt[rem];
        mul *= 10;
        mul %= 2019;
    }
    cout << answer;
}