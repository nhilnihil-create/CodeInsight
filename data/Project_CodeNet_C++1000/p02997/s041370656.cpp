#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    int n , k;
    cin >> n >> k;

    int p = (n - 1) * (n - 2) / 2;

    if (p < k) {
        cout << -1;
        return 0;
    }

    set<array<int , 2> > pairs;
    vector<array<int , 2> > edges;

    for (int i = 2 ;i < n ;i++)
        for (int j = i + 1 ;j <= n ;j++)
            pairs.insert({i , j});

    for (int i = 2 ;i <= n ;i++)
        edges.push_back({1 , i});

    while (p > k) {
        edges.push_back(*pairs.begin());
        pairs.erase(pairs.begin());
        p--;
    }

    cout << edges.size() << '\n';
    for (auto &e : edges)
        cout << e[0] << ' ' << e[1] << '\n';
}
