#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int mat[n][m]{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    int vec[m]{};
    for (int j = 0; j < m; j++) {
        cin >> vec[j];
    }
    
    int res[n]{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i] += mat[i][j] * vec[j];
        }
        cout << res[i] << endl;
    }
    
    return 0;
}
