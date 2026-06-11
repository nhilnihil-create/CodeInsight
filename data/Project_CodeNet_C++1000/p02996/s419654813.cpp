#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<pair<int, int> > V(N);
    rep(i, N){
        int a, b; cin >> a >> b;
        V[i] = make_pair(b, a);
    }
    sort(V.begin(), V.end());

    ll total = 0;
    rep(i, N){
        total += V[i].second;
        if (total > V[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}