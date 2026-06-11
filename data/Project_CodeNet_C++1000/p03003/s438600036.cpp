#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;   cin >> n >> m;
    long long mod = 1e9+7;
    vector<int> s(n), t(m);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];

    vector<vector<long long> > u(n+1, vector<long long>(m+1, 0)), v(n+1, vector<long long>(m+1, 1));
    u[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j])
                u[i+1][j+1] = v[i][j];
            
            v[i+1][j+1] = (u[i+1][j+1] + v[i+1][j] + v[i][j+1] - v[i][j]) % mod;
        }
    }

    cout << (v[n][m] + mod) % mod << endl;
    return 0;
}   