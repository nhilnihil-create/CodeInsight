#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> X(N),L(N);
    for (int i=0;i<N;i++) cin >> X[i] >> L[i];
    vector<pair<int,int>> r(N);
    for (int i=0;i<N;i++){
        r[i].first = X[i] + L[i];
        r[i].second = X[i] - L[i];
    }
    sort(r.begin(),r.end());
    int pos = - INF;
    int ans = 0;
    for (int i=0;i<N;i++){
        if (r[i].second >= pos) {
            ans++;
            pos = r[i].first;
        }
    }
    cout << ans << "\n";

    return 0;
}