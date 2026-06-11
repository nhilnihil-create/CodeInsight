#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
template<class F>auto recursive(F f){return[f](auto...a){return f(f,a...);};}
template<class T>using rev_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>using vector2d=vector<vector<T>>;
struct fixprec{int p;fixprec(int p):p(p){}};
ostream&operator<<(ostream&o,fixprec f){return o<<fixed<<setprecision(f.p);}
int main() {
    i64 N, P;
    cin >> N >> P;
    string S;
    cin >> S;
    reverse(WHOLE(S));
    i64 ans = 0;
    if(P == 2 || P == 5) {
        for(int i = 0; i < N; i++) {
            if((S[i] - '0') % P == 0) {
                ans += N - i;
            }
        }
    } else {
        i64 p10 = 1;
        i64 cur = -1;
        vector<i64> m(P, 0);
        m[0]++;
        for(int i = 0; i < N; i++) {
            cur = (cur < 0 ? 0 : cur) + p10 * (S[i] - '0');
            cur %= P;
            m[cur]++;
            p10 = (p10 * 10) % P;
        }
        for(int i = 0; i < P; i++) {
            ans += (m[i] * (m[i] - 1)) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}