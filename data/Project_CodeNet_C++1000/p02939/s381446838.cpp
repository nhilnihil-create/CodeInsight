#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9 + 7;
const int INF = 2e18;

signed main() {
    string S;
    cin >> S;
    int ans = 0;
    {
        // left;
        int count = 1;
        string check = S.substr(0, 1);
        int before = 1;
        for (int i = 1; i < S.length(); i++) {
            string now = S.substr(before, i - before + 1);
            if (now != check) {
                count++;
                before = i + 1;
                check = now;
            }
        }
        ans = max(ans, count);
    }
    {
        // right
        int count = 1;
        string check = S.substr(S.length() - 1, 1);
        int before = S.length() - 2;
        for (int i = S.length() - 2; i >= 0; i--) {
            string now = S.substr(before, i - before + 1);
            if (now != check) {
                count++;
                before = i - 1;
                check = now;
            }
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
}