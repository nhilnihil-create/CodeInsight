#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
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
        string s;
        cin >> s;
        
        const int n = s.size();
        
        vector<int> a(n);
        REP(i, n) a[i] = s[i] - '0';
        reverse(a.begin(), a.end());

        auto dp = make_v(n + 1, 2, (int)1e8);
        dp[0][0] = 0;

        REP(i, n) {
                dp[i + 1][1] = min(dp[i][1] + (9 - a[i]), dp[i][0] + (10 - a[i]));
                dp[i + 1][0] = min(dp[i][1] + (a[i] + 1), dp[i][0] + a[i]);
        }

        cout << min(dp[n][0], dp[n][1] + 1) << endl;

        return 0;
}
