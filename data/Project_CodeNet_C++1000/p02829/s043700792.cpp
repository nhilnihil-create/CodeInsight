#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;
    int ans[] = {1, 2, 3};
    for (int s : ans) {
        if (s != a && s != b) cout << s << endl;
    }
    return 0;
}