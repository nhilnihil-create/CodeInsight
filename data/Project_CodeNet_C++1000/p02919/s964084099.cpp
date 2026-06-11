#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int inf = 2e18;
const int mod = 1e9 + 7;

signed main() {
    int N;
    cin >> N;
    vector<int> a(N), idx(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        --a[i];
        idx[a[i]] = i;
    }
    int ans = 0;
    set<int> S;
    for (int i = N - 1; i >= 0; i--) {
        int inidx = idx[i];
        S.insert(inidx);
        auto itr = S.find(inidx);
        vector<int> left(2, -1), right(2, N);
        for (int j = 0; j < 2; j++) {
            if (itr == S.begin()) break;
            --itr;
            left[j] = *itr;
        }
        itr = S.find(inidx);
        for (int j = 0; j < 2; j++) {
            ++itr;
            if (itr == S.end()) break;
            right[j] = *itr;
        }
        left[1] = left[0] - left[1];
        left[0] = inidx - left[0];
        right[1] = right[1] - right[0];
        right[0] = right[0] - inidx;
        int c = left[0] * right[1] + left[1] * right[0];
        ans += c * (i + 1);
    }
    cout << ans << endl;
}
