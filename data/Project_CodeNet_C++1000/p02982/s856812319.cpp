#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,D;
    cin >> N >> D;
    vector<vector<int>>X(N,vector<int>(D));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < D; j++) {
            cin >> X[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            int x = 0;
            for(int k = 0; k < D; k++) {
                x+=abs(X[i][k]-X[j][k])*abs(X[i][k]-X[j][k]);
            }
            for(int k = 0; k*k <= x; k++) {
                if(k*k == x) {
                    ans++;
                }
            }
        }
    }
    cout << ans/2 << endl;
}
