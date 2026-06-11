#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++) {
            //cout << i << " " << j << endl;
            ans++;
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = i+1; j < m; j++) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;        
}