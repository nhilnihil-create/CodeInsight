#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    map<string, int> m;
    rep(i, n) {
        string tmp;
        cin >> tmp;
        if(m.find(tmp) == m.end())
            m[tmp] = 1;
        else {
            m[tmp] += 1;
        }
    }
    cout << m.size() << endl;

    return 0;
}