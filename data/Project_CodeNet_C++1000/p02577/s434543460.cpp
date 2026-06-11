#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,-1,0,1 };
const int LIT = 1e9 + 7;
int n, m;

void solve() {
    string x;
    cin >> x;
    int sum = 0;
    for (int i = 0; i < x.length(); i++) {
        sum += x[i] - '0';
    }
    if (sum % 9 == 0) cout << "Yes\n";
    else cout << "No\n";

}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
