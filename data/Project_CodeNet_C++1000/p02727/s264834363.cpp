#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    
    vector<int> p(a), q(b), r(c);
    rep(i,a) {
        cin >> p[i];
    }
    rep(i,b) {
        cin >> q[i];
    }
    rep(i,c) {
        cin >> r[i];
    }
    
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    
    vector<int> total;
    rep(i,x) {
        total.push_back(p[i]);
    }
    rep(i,y) {
        total.push_back(q[i]);
    }
    rep(i,c) {
        total.push_back(r[i]);
    }
    
    sort(total.rbegin(), total.rend());
    long int sum = 0;
    rep(i,x+y) {
        sum += total[i];
    }
    
    cout << sum << endl;
    
    return 0;
}


