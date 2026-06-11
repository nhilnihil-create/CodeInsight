#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

const int BIG_NUM = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int len = s.size();
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += s[i] - '0';
    }
    if(sum % 9 == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
