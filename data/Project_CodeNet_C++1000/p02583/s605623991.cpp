#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    rep(i, N) cin >> L[i];
    sort(all(L));
    int ans = 0;
    for (int i=0; i<N-2; ++i) {
        for (int j=i+1; j<N-1; ++j) {
            if (L[i] == L[j]) continue;
            for (int k=j+1; k<N; ++k) {
                if (L[j] == L[k]) continue;
                if (L[k] < L[i]+L[j]) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}