#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    map<P, int> cnts;

    for(int i=0; i<N; i++) {
        map<P, int> temp;
        for(int j=0; j<N; j++) {
            P tmp = P(x[i]-x[j], y[i]-y[j]);
            if(i != j) temp[tmp]++;
        }
        for(auto& p: temp) {
            cnts[p.first]++;
        }
    }

    int mx = 0;
    for(auto& p: cnts) {
        mx = max(mx, p.second);
    }

    cout << N-mx << endl;
    return 0;
}