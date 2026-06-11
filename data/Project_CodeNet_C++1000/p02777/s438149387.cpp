#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string a, b;
    cin >> a >> b;
    map<string, int> mp;
    int x, y;
    cin >> x >> y;
    mp[a] += x;
    mp[b] += y;
    string c;
    cin >> c;
    mp[c]--;
    printf("%d %d\n", mp[a], mp[b]);
    return 0;
}