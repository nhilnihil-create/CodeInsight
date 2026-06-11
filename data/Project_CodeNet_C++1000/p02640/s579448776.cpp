#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using ll = long long;

int main() {
    int x , y;
    cin >> x >> y;

    bool ans = true;
    if (x * 2 <= y && y <= x * 4 && y % 2 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}