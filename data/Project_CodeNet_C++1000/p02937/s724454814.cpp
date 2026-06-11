#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
        return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
        constexpr int M = 26;

        string s, t;
        cin >> s >> t;

        const int n = s.length(), m = t.length();

        string ss = " " + s + s;
        auto ta = make_v(2 * n + 1, M, -1);
        vector<int> next(M, -1);

        for (int i = 2 * n; i >= 0; i--) {
                rep (j, M) {
                        ta[i][j] = next[j];
                }
                
                rep (j, M) {
                        if (i > 0 && ss[i] - 'a' == j) {
                                next[j] = i;
                        } else {
                                next[j] = ta[i][j];
                        }
                }
        }

        ll i = 0, c = 0;
        rep (j, m) {
                if (ta[i][t[j] - 'a'] == -1) {
                        cout << -1 << endl;
                        return 0;
                } else {
                        if (ta[i][t[j] - 'a'] > n) {
                                i = ta[i][t[j] - 'a'] - n;
                                c++;
                        } else {
                                i = ta[i][t[j] - 'a']; 
                        }
                }
        }

        cout << n * c + i << endl;

        return 0;
}
