#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    int N, K;
    cin >> N >> K;

    int kmax = (N - 1) * (N - 2) / 2;
    if (K > kmax){
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int, int>> g;
    for (int i = 2; i <= N; i++) {
        g.emplace_back(1, i);
    }
    int k = kmax;
    for (int i = 2; i <= N; i++) {
        if (k == K)
            break;
        for (int j = i + 1; j <= N; j++) {
            g.emplace_back(i, j);
            k--;
            if (k == K)
                break;
        }
    }
    cout << g.size() << endl;
    for (auto p : g) {
        printf("%d %d\n", p.first, p.second);
    }
}