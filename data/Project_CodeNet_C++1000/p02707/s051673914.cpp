#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    rep(i, n - 1) {
        int tmp;
        cin >> tmp;
        if(m.find(tmp) == m.end())
            m[tmp] = 1;
        else {
            m[tmp] += 1;
        }
    }
    rep(i, n) { cout << m[i + 1] << endl; }

    return 0;
}