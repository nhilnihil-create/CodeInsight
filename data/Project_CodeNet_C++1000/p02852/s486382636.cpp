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
const int INF = 9e18;

struct UnionFind {
    vector< int > data;

    UnionFind(int sz) {
        data.assign(sz, -1);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k) {
        if(data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k) {
        return (-data[find(k)]);
    }
};

struct info {
    int cost, first, second;

    bool operator<(const info &a) const { return a.cost < cost; }
};

signed main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    vector<int> ans;
    for (int i = 0; i < S.length() - 1;) {
        int move = 0;
        for (int j = M; j >= 1; j--) {
            if (i + j >= S.length()) continue;
            if (S[i + j] == '0') {
                move = j;
                break;
            }
        }
        if (move == 0) {
            cout << -1 << endl;
            return 0;
        }
        ans.push_back(move);
        i += move;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
    }
}
