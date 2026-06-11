#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
int u[N][N] , d[N][N] , l[N][N] , r[N][N];

int main() {
    int n , m;
    cin >> n >> m;
    n += 2 ;
    m += 2;
    vector<string> grid(n , string(m , '#'));
    for (int i = 1 ;i < n - 1;i++)
        for (int j = 1 ;j < m - 1 ;j++)
            cin >> grid[i][j];

    for (int i = 1 ;i < n - 1 ;i++) {
        for (int j = 1 ;j < m - 1 ;j++)
            if (grid[i][j] != '#')
                l[i][j] = l[i][j - 1] + 1;

        for (int j = m - 2 ;j >= 1 ;j--)
            if (grid[i][j] != '#')
                r[i][j] = r[i][j + 1] + 1;
    }

    for (int j = 1 ;j < m - 1 ;j++) {
        for (int i = 1 ;i < n - 1 ;i++)
            if (grid[i][j] != '#')
                u[i][j] = u[i - 1][j] + 1;

        for (int i = n - 2 ;i >= 1 ;i--)
            if (grid[i][j] != '#')
                d[i][j] = d[i + 1][j] + 1;
    }


    int ans = 0;
    for (int i = 1 ;i < n - 1 ;i++)
        for (int j = 1 ;j < m - 1 ;j++)
            ans = max(ans , u[i][j] + d[i][j] + l[i][j] + r[i][j] - 3);

    cout << ans;
}
