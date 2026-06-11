#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

vector<int> g[200005];
int d[200005];

void dfs(int x, int p) {
    for (int i : g[x]) if (i != p) {
        d[i] += d[x];
        dfs(i, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int a;
    string s;
    cin >> a >> s;
    if (a >= 3200) cout << s;
    else cout << "red";
}
