#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<int> q;
    rep(i,n) {
        cin >> a[i];
        q.push(a[i]);
    }
    rep(i,n) {
        int t = q.top(); q.pop();
        if (t != a[i]) {
            cout << t << endl;
            q.push(t);
        }
        else {
            int u = q.top(); q.pop();
            cout << u << endl;
            q.push(t);
            q.push(u);
        }
    }
    
    return 0;
}