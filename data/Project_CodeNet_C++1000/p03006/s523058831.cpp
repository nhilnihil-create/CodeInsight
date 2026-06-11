#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i=0;i<N;i++) cin >> x[i] >> y[i];
    int ans = N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (x[i] == x[j] && y[i] == y[j]) continue;
            int cnt = N;
            int p = x[j] - x[i];
            int q = y[j] - y[i];
            for (int k=0;k<N;k++){
                for (int l=0;l<N;l++){
                    if (x[l]-x[k] == p && y[l]-y[k]==q) cnt--;
                }
            }
            ans = min(ans,cnt);
        }
    }
    cout << ans << "\n";
}