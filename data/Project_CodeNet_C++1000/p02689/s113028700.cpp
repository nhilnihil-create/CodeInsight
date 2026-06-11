#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    vector<vector<int>> g(N, vector<int>());
    
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        bool highest = true;
        for (auto elem : g[i])
        {
            if(H[elem] < H[i]){

            } else {
                highest = false;
                break;
            }
        }
        if(highest) ans++;
    }
    cout << ans << endl;

    return 0;
}
