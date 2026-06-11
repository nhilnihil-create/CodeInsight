#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;

int main(void)
{
    int N;
    cin >> N;
    Graph G(N+1);
    int a;

    for(int i = 2;i <= N; i++) {
        cin >> a;
        G[a].push_back(1);
    }

    for(int i = 1; i <= N; i ++) {
        cout << G[i].size() << endl;
    }
    return 0;
}