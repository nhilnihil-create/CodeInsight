#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> list(M);
    rp(i, 0, N) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a <= M) {
            a--;
            list.at(a).emplace_back(b);
        }
    }
    int ans = 0;
    priority_queue<int> Q;
    
    rp(i, 0, M) {
        for(auto x: list.at(i)) Q.push(x);
        if(!Q.empty()){
            ans += Q.top();
            Q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}