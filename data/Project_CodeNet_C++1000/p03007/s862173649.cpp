#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    i64 N;
    cin >> N;
    vector<i64> p, m;
    rep(i, N){
        i64 a; cin >> a;
        if(a > 0) p.emplace_back(a);
        else m.emplace_back(a);
    }

    sort(p.rbegin(), p.rend());
    sort(all(m));

    if(p.size() == 0) {
        p.emplace_back(m[m.size() - 1]);
        m.pop_back();
    }
    if(m.size() == 0) {
        m.emplace_back(p[p.size() - 1]);
        p.pop_back();
    }
    
    i64 M = 0;
    for(auto& a : p) M += a;
    for(auto& a : m) M -= a;

    stack<i64> stk;
    stk.emplace(m[m.size() - 1]);

    cout << M << endl;
    i64 x, y;
    rep(i, p.size() - 1){
        x = stk.top(); stk.pop();
        y = p[i];
        cout << x << " " << y << endl;
        stk.emplace(x - y);
    }

    x = p[p.size() - 1];
    y = stk.top(); stk.pop();
    cout << x << " " << y << endl;
    stk.emplace(x - y);

    rep(i, m.size() - 1){
        x = stk.top(); stk.pop();
        y = m[i];
        cout << x << " " << y << endl;
        stk.emplace(x - y);
    }
}