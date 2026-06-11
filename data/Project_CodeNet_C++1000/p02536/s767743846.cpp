#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define PI acos(-1)
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<typename T> using v2 = vector<vector<T>>;
template<typename T> using v3 = vector<vector<vector<T>>>;
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int MOD = 1e9 + 7;
const int INF = 1e9 + 200;
const ll INFLL = 2e18 + 200;

class UnionFind {
private:
    vector<int> data;

public:
    explicit UnionFind(size_t data_size) : data(data_size, -1)  {}

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(size_t index) {
        if (data[index] < 0) return index;
        else return (data[index] = find(data[index]));
    }

    int size(size_t index) {
        return (-data[find(index)]);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        uf.unite(A, B);
    }
    set<int> check;
    for (int i = 0; i < N; i++) {
        check.insert(uf.find(i));
    }
    cout << check.size() - 1 << endl;
}