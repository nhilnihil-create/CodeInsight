#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1; i<=n;i++)
#define ALL(a) a.begin(),a.end()
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
typedef long long int ll;
vector<vector<int>> G;
vector<bool> visit;
vector<int> point;
void dfs(int a,int p) {
    for (int i : G[a]) {
        if (i == p) continue;
        point[i] += point[a];
        dfs(i,a);
    }
}
int main() {
    int n, q,a,b; cin >> n >> q;
    G.resize(n);point.resize(n, 0); visit.resize(n,0);
    rep(i, n-1) {
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }rep(i, q) {
        cin >> a >> b; a--;
        point[a] += b;
    }dfs(0,0);
    for (int i : point) cout << i << " ";
    cout << endl;
}