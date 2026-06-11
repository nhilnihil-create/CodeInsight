#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    P p;
    vector<P> v(n);
    rep(i, n) {
        cin >> p.second >> p.first;
        v[i] = p;
    }
    sort(v.begin(), v.end());
    int passedTime = 0;
    rep(i, n) {
        // cout << "B:" << v[i].first << "A:" << v[i].second << endl;
        passedTime += v[i].second;
        if(passedTime > v[i].first) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}