#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}}; ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
int main() {
    i64 N;
    cin >> N;
    i64 ans = 0;
    ans = (N * (N + 1) * (N + 2)) / 6;
    for(int i = 0; i < N - 1; i++) {
        i64 u, v;
        cin >> u >> v;
        u--, v--;
        if(v < u) swap(u, v);
        ans -= (u + 1) * (N - v);
    }
    cout << ans << endl;
    return 0;
}