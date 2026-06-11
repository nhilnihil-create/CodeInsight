#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<P> B(N);
    rep(i, N){
        int x, y; cin >> x >> y;
        B[i] = make_pair(x, y);
    }

    map<P, int> m;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(i == j)continue;
            int a = B[i].first - B[j].first;
            int b = B[i].second - B[j].second;
            P p = make_pair(a, b);
            m[p]++;
        }
    }

    int ma = 0;
    for(auto p : m){
        auto value = p.second;
        ma = max(ma, value);
    }

    cout << N - ma << endl;

    return 0;
}